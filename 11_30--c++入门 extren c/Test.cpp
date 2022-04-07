#include <iostream>
using namespace std;

//// 引用的价值
//// 1、做参数 --  a、提高效率 b、形参的修改，可以影响实参（输出型参数）
//
////#define N 100 
//const int N = 10;
//
//struct Stack
//{
//	//int* a;
//	//int top;
//	//int capacity;
//
//	int a[N];
//	int top;
//};
//
//void Func1(struct Stack st)
//{}
////32位机器下占用四百字节
//void Func2(struct Stack* pst)
//{}
////32位机器下占用四字节
//void Func3(struct Stack& rst)
//{}
//
//void StackInit(struct Stack* pst)
//{}
////输出型参数
//void StackInit(struct Stack& rst)
//{}
////输出型参数
//int main()
//{
//	//引用的价值不在当前场景
//	int a = 10;
//	int& b = a;
//	int& c = b;
//
//	struct Stack st;
//	Func1(st);
//	Func2(&st);
//	Func3(st);
//
//	StackInit(&st);
//	StackInit(st);//引用和指针构成函数重载
//
//	return 0;
//}

//const int N = 10;
//// 2.引用做返回值
//int Add(int a, int b) //不要返回局部变量的引用
//{
//	int c = a + b;
//	return c;
//}
//
////int At(int i)
//int& At(int i)
//{
//	static int a[N];
//	return a[i];
//}
//
//int main()
//{
//	for (size_t i = 0; i < N; i++)
//	{
//		At(i) = 10 + i;
//	}
//
//	for (size_t i = 0; i < N; i++)
//	{
//		cout<<At(i)<<" ";
//	}
//	cout << endl;
//
//	return 0;
//}
//
//int& f()
//{
//	int* p = (int*)malloc(100);
//	return *p;
//}
//
//int main()
//{
//	int ret = f();
//	cout << &f() << endl;
//	cout << &ret << endl;
//	return 0;
//}

////#define N 100 
//const int N = 100;
//
//struct Stack
//{
//	//int* a;
//	//int top;
//	//int capacity;
//	int a[N];
//	int top;
//};
//struct Stack Add(struct Stack* pst)
//{
//	pst->a[0] = 1;
//
//	return *pst;
//}
//
//int main()
//{
//	struct Stack st;
//	st = Add(&st);
//	return 0;
//}

////使用引用传参，如果函数中不改变参数的值，建议使用引用传参
//void StackPrint(struct Stack& st)
//{}
//
//int main()
//{
//	int x = 10;
//	int& y = x;
//	int& z = y;
//
//	cout << x << endl;
//	cout << y << endl;
//	cout << z << endl;
//
//  // 权限放大 -- 不行
//	const int a = 10;//可读不可写
//	//int& b = a;
//
//	// 权限不变 -- 可以
//	const int c = 20;
//	const int& d = c;
//
//	// 权限缩小 -- 可以
//	int e = 30;
//	const int& f = e;
//
//	double dd = 11.11;
//	int i1 = dd;
//	//int& i2 = d;
//	const int& i3 = dd;
//
//	int x1 = 1, x2 = 2;
//	const int& ret = x1 + x2;
//	printf("%p\n", &ret);
//
//	return 0;
//}

//void f1(int* p)
//{
//	*p = 10;
//}
//
//void f2(int& r)
//{
//	r = 10;
//}
//
//int main()
//{
//	//int x = 0;
//	//int& a = x;
//	//int* p;
//
//	f1(NULL);
//	f1(0);
//	//f2(NULL);
//	//f2(0);
//	int a = 0;
//	f1(&a);
//	f2(a);
//
//	return 0;
//}
//// C++项目
//// 告诉C++编译器，extern "C"{}里面的函数是C编译器编译的，链接的时候用C的函数名规则去找，就可以链接上
extern "C"
{
    #include "../ST/Stack.h"
}
    
bool isValid(const char* s) {
    ST st;
    StackInit(&st);
    //左括号入栈
    while (*s)
    {
        if ((*s == '(') ||
            (*s == '[') ||
            (*s == '{'))
        {
            StackPush(&st, *s);// call ?StackPush@@YAXPAUStack@@H@Z
            ++s;
        }
        //右括号出栈匹配
        else
        {
            //遇到右括号了，但是栈里面没有数据，
            //说明前面没有左括号，不匹配，返回false
            if (StackEmpty(&st))
            {
                StackDestroy(&st);
                return false;
            }
            STDataType top = StackTop(&st);
            StackPop(&st);

            if ((*s == ')' && top != '(') ||
                (*s == ']' && top != '[') ||
                (*s == '}' && top != '{'))
            {
                //中途返回需要destroy 否则就会内存泄露     
                StackDestroy(&st);
                return false;
            }

            else
            {
                ++s;
            }

        }

    }
    //如果栈不是空，说明栈中还有左括号未出
    //没有匹配，返回false
    bool ret = StackEmpty(&st);
    StackDestroy(&st);
    return ret;
}

int main()
{
    //cout<<isValid("{[]}")<<endl;
    //cout<<isValid("([)]")<<endl;
    printf("%d\n", isValid("{[]}"));
    printf("%d\n", isValid("([)]"));
    return 0;
}

//// C 项目
//#include "../../DS/DS/Stack.h"
//
//bool isValid(char * s){
//	ST st;
//	StackInit(&st);
//	while (*s)
//	{
//		if (*s == '('
//			|| *s == '{'
//			|| *s == '[')
//		{
//			StackPush(&st, *s);
//			++s;
//		}
//		else
//		{
//			// 遇到右括号了，但是栈里面没有数据，说明
//			// 前面没有左括号，不匹配，返回false
//			if (StackEmpty(&st))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//
//			STDataType top = StackTop(&st);
//			StackPop(&st);
//			if ((*s == '}' && top != '{')
//				|| (*s == ']' && top != '[')
//				|| (*s == ')' && top != '('))
//			{
//				StackDestroy(&st);
//				return false;
//			}
//			else
//			{
//				++s;
//			}
//		}
//	}
//
//	// 如果栈不是空，说有栈中还有左括号未出
//	// 没有匹配，返回是false
//	bool ret = StackEmpty(&st);
//	StackDestroy(&st);
//	return ret;
//}
//
//int main()
//{
//	//cout << isValid("{[]}") << endl;
//	//cout << isValid("([)]") << endl;
//	printf("%d\n", isValid("{[]}"));
//	printf("%d\n", isValid("([)]"));
//
//	return 0;
//}

// 调用函数，需要建立栈帧，栈帧中要保存一些寄存器，结束后又要恢复...
// 可以看到这些都是有消耗的。
// 对于频繁调用的小函数，能否优化一下？
// C -- 宏

//inline int Add(int x, int y)
//{
//	int ret = x + y;
//	return ret;
//}
//
//int main()
//{
//	Add(1, 2);
//	Add(1, 2);
//	Add(1, 2);
//	Add(1, 2);
//	Add(1, 2);
//	Add(1, 2);
//
//	return 0;
//}

//宏是替换 验证宏就替换一下看看正不正确
//写一个两个数相加的宏 -- 技巧，记住宏原理是替换
//#define ADD(int x, int y) { return x + y;}
//#define ADD(int x, int y) return x + y;
//#define ADD(int x, int y) x + y;
//#define ADD(x, y) x + y;
//#define ADD(x, y) x + y
//#define ADD(x, y) (x + y)
#define ADD(x, y) ((x) + (y))

//// 有了inline, 我们就不需要用C的宏，因为宏很复杂，很容易出错
//int main()
//{
//	cout << ADD(1, 2) << endl; //cout << 1 + 2; << endl;
//	cout << ADD(3, 4) << endl;  // cout << 3 + 4 << endl;
//	cout << 10 * ADD(3, 4) << endl; // cout << 10*3+4 << endl;
//
//	int a = 0, b = 1;
//	cout << ADD(a | b, a&b); //cout << (a|b + a&b) << endl;
//	return 0;
//}

//inline int Add(int x, int y)
//{
//	int ret = x + y;
//	return ret;
//}
//
//inline void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}

//int main()
//{
//	int ret = Add(1, 2);
//	cout << ret << endl;
//
//	int a = 1;
//	int b = 0;
//	cout << a << " " << b << endl;
//
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	return 0;
//}

