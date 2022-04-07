// 11_25.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#include "Stack.h"
struct Student
{
	char name[20];
	int age;
	// ...
};
//int main()
//{
//	// << 流插入
//	// 推荐都可以用，哪个方便就用哪个
//	cout << "hello world" << endl;
//	const char* str = "hello bit";
//	cout << str << endl;
//	int i = 1;
//	double d = 1.11;
//	cout << i << d << endl;
//	printf("%d%.2lf\n", i, d);
//
//	struct Student s = { "鹏哥", 18 };
//	// cpp
//	cout <<"姓名:" <<s.name << endl;
//	cout << "年龄:" << s.age << endl << endl;
//
//	// c
//	printf("姓名:%s\n年龄:%d\n", s.name, s.age);
//
//	// >> 流提取运算符
//	cin >> s.name >> s.age;
//	cout << "姓名:" << s.name << endl;
//	cout << "年龄:" << s.age << endl << endl;
//
//	scanf("%s%d", s.name, &s.age);
//	printf("姓名:%s\n年龄:%d\n", s.name, s.age);
//
//	return 0;
//}
////缺省参数
//void Func(int a = 0)
//{
//    cout << a << endl;
//}
//int main()
//{
//    std::cout << "Hello World!\n";
//    Func(1);
//    //Func();
//}
// 
// 全缺省
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	Func();
//  Func(1);
//	Func(1,2);
//	Func(1,2,3);
//	return 0;
//}
// 
// 半缺省 -- 缺省部分参数 -- 必须从右往左缺省,必须连续缺省
//void Func(int a, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	Func(1);
//	Func(1, 2);
//	Func(1, 2, 3);
//	return 0;
//}

//void Func(int a, int b, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//	Func(1, 2);
//	Func(1, 2, 3);
//	return 0;
//}

//struct Stack
//{
//	int* a;
//	int top;
//	int capacity;
//
//};
//
//void StackInit(struct Stack* ps, int capacity = 4)
//{
//	ps->a = (int*)malloc(sizeof(int) * capacity);
//
//	ps->top = 0;
//	ps->capacity = capacity;
//}
//
//void StackPush(struct Stack* ps, int x)
//{
//	 //...
//}

//int main()
//{
//	struct Stack st;
//	//StackInit(&st); // 不知道栈最多存多少数据，就用缺省值初始化
//	StackInit(&st, 100); // 知道栈最多存100数据，显示传值。这样可以减少增容次数，提高效率
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////
// 函数重载
// 1、参数类型不同
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//
//double Add(double left,double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//
//	return left + right;
//}
//
//// 2、参数个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//
//// 3、参数顺序不同
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//
//// 返回值不同，不能构成重载 -- 调用的时候不能区分
////int f(double d)
////{
////
////}
////
////void f(double d)
////{
////
////}
//
//int main()
//{
//	Add(1, 2);
//	Add(1.1, 2.2);
//
//	f();
//	f(1);
//
//	f(10, 'A');
//	f('A', 10);
//
//	f(1.1);
//
//	return 0;
//}

// 1、缺省值不同，不能构成重载
//void f(int a)
//{
//	cout << "f()" << endl;
//}
//
//void f(int a = 0)
//{
//	cout << "f(int a)" << endl;
//}

// 2、构成重载，但是使用时会有问题 ： f(); // 调用存在歧义
//void f()
//{
//	cout << "f()" << endl;
//}
//
//void f(int a = 0)
//{
//	cout << "f(int a)" << endl;
//}
//
//int main()
//{
//	// f(); // 调用存在歧义
//	 f(1);
//
//	return 0;
//}

//void f()
//{
//	cout << "f()" << endl;
//}
//
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}

int main()
{
	/*
	f();
	f(1);*/
	SLTNode* plist = NULL;
	SListPrint(plist );
	return 0;
}

//c++ "void __cdecl SListPrint(struct SListNode *)" (? SListPrint@@YAXPAUSListNode@@@Z)，函数 _main 中引用了该符号	11_25	D : \code\cpp\11_25\Test.obj	1
//c LNK2019	无法解析的外部符号 _SListPrint，函数 _main 中引用了该符号	11_25	D:\code\cpp\11_25\Test.obj	1	
