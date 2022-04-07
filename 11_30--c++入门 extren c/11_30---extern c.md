# extern "C"

## 一、引用的价值

==引用的概念就是为了解决指针的不足 指针的不足：复杂==

**引出引用为了让一些复杂的地方简单化**

不要返回局部变量的引用



处理错误的方法

==有时候编译出错需要用排除法 加了一个新的符号报错就先去掉或者屏蔽它看报不报错，如果还报错就是其他 代码或者符号的原因==

**0x3000报错**代表出现了一个特殊符号 不是英文的

### 1、引用做参数

**引用真正的价值体现**

**1、做参数 **

**2、做返回值**

~~~Cpp
// 引用的价值
// 1、做参数 --  a、提高效率 b、形参的修改，可以影响实参（输出型参数）

//#define N 100 
const int N = 10;

struct Stack
{
	//int* a;
	//int top;
	//int capacity;

	int a[N];
	int top;
};

void Func1(struct Stack st)
{}
//32位机器下占用四百字节
void Func2(struct Stack* pst)
{}
//32位机器下占用四字节
void Func3(struct Stack& rst)
{}

void StackInit(struct Stack* pst)
{}
//输出型参数
void StackInit(struct Stack& rst)
{}
//输出型参数
int main()
{
    //引用的价值不在当前场景
	int a = 10;
	int& b = a;
	int& c = b;

	struct Stack st;
	Func1(st);
	Func2(&st);
	Func3(st);

	StackInit(&st);
	StackInit(st);//引用和指针构成函数重载

	return 0;
}
~~~

### 2、引用做返回值

![image-20220306205429329](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220306205429329.png)

==可以返回的对象：全局变量 静态变量 成员变量 malloc动态申请==

==所有传值返回都会生成临时对象==

![image-20220306211720029](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220306211720029.png)

后面运算符重载就体现出引用做返回值的价值

~~~cpp
const int N = 10;
// 2.引用做返回值
int Add(int a, int b) //不要返回局部变量的引用
{
	int c = a + b;
	return c;
}

//int At(int i) //临时对象为右值
int& At(int i)
{
	static int a[N];
	return a[i];
}

int main()
{
	for (size_t i = 0; i < N; i++)
	{
		At(i) = 10 + i;
	}

	for (size_t i = 0; i < N; i++)
	{
		cout<<At(i)<<" ";
	}
	cout << endl;

	return 0;
}

int& f()
{
	int* p = (int*)malloc(100);//p还是局部对象
	return *p;
}

int main()
{
	int ret = f();
	cout << &f() << endl;
	cout << &ret << endl;
	return 0;
}
~~~

### 3、常引用

![image-20220306213727484](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220306213727484.png)

**如果是输出型参数，就使用引用**

~~~cpp
//使用引用传参，如果函数中不改变参数的值，建议使用引用传参
void StackPrint(struct Stack& st)
{}

int main()
{
	int x = 10;
	int& y = x;
	int& z = y;

	cout << x << endl;
	cout << y << endl;
	cout << z << endl;

    // 权限放大 -- 不行
	const int a = 10;//可读不可写
	//int& b = a;

	// 权限不变 -- 可以
	const int c = 20;
	const int& d = c;

	// 权限缩小 -- 可以
	int e = 30;
	const int& f = e;

	double dd = 11.11;
	int i1 = dd;
	//int& i2 = d;
	const int& i3 = dd;

	int x1 = 1, x2 = 2;
	const int& ret = x1 + x2;
	printf("%p\n", &ret);

	return 0;
}
~~~

### 4、指针引用区别

![image-20220306220544075](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220306220544075.png)

==有些知识需要逐步学习，然后融会贯通==

~~~cpp
void f1(int* p)
{
	*p = 10;
}

void f2(int& r)
{
	r = 10;
}

int main()
{
	//int x = 0;
	//int& a = x;
	//int* p;

	f1(NULL);
	f1(0);
	//f2(NULL);
	//f2(0);
	int a = 0;
	f1(&a);
	f2(a);

	return 0;
}
~~~

## 二、extern "C"

### 1、应用场景

![image-20220306221039149](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220306221039149.png)

### 2、创建静态库

[vs2019创建静态库](https://blog.csdn.net/luoyu510183/article/details/106026541)



#### 2.1 c静态库

~~~c
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

	void StackInit(ST* ps);
	void StackDestroy(ST* ps);
	void StackPush(ST* ps, STDataType x);
	void StackPop(ST* ps);
	STDataType StackTop(ST* ps);
	int StackSize(ST* ps);
	bool StackEmpty(ST* ps);

#include "Stack.h"

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0; //ps->top = -1;
	ps->capacity = 0;
}
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
}
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->capacity == ps->top) 
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("malloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)
{
	assert(ps);
	//assert(ps->top > 0);
	assert(!StackEmpty(ps));
	ps->top--;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top-1];
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top ;
}
bool StackEmpty(ST* ps)
{
	/*if (ps->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}*/
	assert(ps);
	return ps->top == 0;
}
~~~

#### 2.2 c++静态库

~~~Cpp
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;
 
#ifdef __cplusplus
extern "C"
{
#endif  

	void StackInit(ST* ps);
	void StackDestroy(ST* ps);
	void StackPush(ST* ps, STDataType x);
	void StackPop(ST* ps);
	STDataType StackTop(ST* ps);
	int StackSize(ST* ps);
	bool StackEmpty(ST* ps);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

EXTERN_C void StackInit(ST* ps);
EXTERN_C void StackDestroy(ST* ps);
EXTERN_C void StackPush(ST* ps, STDataType x);
EXTERN_C void StackPop(ST* ps);
EXTERN_C STDataType StackTop(ST* ps);
EXTERN_C int StackSize(ST* ps);
EXTERN_C bool StackEmpty(ST* ps);

#include "Stack.h"

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0; //ps->top = -1;
	ps->capacity = 0;
}
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
}
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->capacity == ps->top) 
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("malloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)
{
	assert(ps);
	//assert(ps->top > 0);
	assert(!StackEmpty(ps));
	ps->top--;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top-1];
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top ;
}
bool StackEmpty(ST* ps)
{
	/*if (ps->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}*/
	assert(ps);
	return ps->top == 0;
}
~~~

### 3、c++调用c

#### 3.1第一步包含头文件 

==c++的项目会call ?StackPush@@YAXPAUStack@@H@Z这一段函数名去找函数，c++ 和 c 生成的函数名修饰规则不一样==

==ST里面不存在这个函数的符号表和映射==  **它是用c的 c是没有函数名修饰规则的**   ==call StackPush==

~~~cpp
// C++项目
// 告诉C++编译器，extern "C"{}里面的函数是C编译器编译的，链接的时候用C的函数名规则去静态库中找，就可以链接上
extern "C"
{
    #include "../ST/Stack.h" //相对路径 //包头文件
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
            StackPush(&st, *s);// call ?StackPush@@YAXPAUStack@@H@Z (?)
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
    cout<<isValid("{[]}")<<endl;
    cout<<isValid("([)]")<<endl;

    return 0;
}
~~~

#### 3.2第二步 链接定义

![image-20220307161307368](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220307161307368.png)

==公司中几十人为一个部门，协作的时候都是写好一个库，只需要你的头文件，不需要编译你的代码==

==又或者公司间合作不泄露源代码，更安全一些==

![image-20220307180219194](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220307180219194.png)

### 4、c调用c++ 

~~~c
// C 项目
#include "../../DS/DS/Stack.h"

bool isValid(char * s){
	ST st;
	StackInit(&st);
	while (*s)
	{
		if (*s == '('
			|| *s == '{'
			|| *s == '[')
		{
			StackPush(&st, *s);
			++s;
		}
		else
		{
			// 遇到右括号了，但是栈里面没有数据，说明
			// 前面没有左括号，不匹配，返回false
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return false;
			}

			STDataType top = StackTop(&st);
			StackPop(&st);
			if ((*s == '}' && top != '{')
				|| (*s == ']' && top != '[')
				|| (*s == ')' && top != '('))
			{
				StackDestroy(&st);
				return false;
			}
			else
			{
				++s;
			}
		}
	}

	// 如果栈不是空，说有栈中还有左括号未出
	// 没有匹配，返回是false
	bool ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}

int main()
{
	//cout << isValid("{[]}") << endl;
	//cout << isValid("([)]") << endl;
	printf("%d\n", isValid("{[]}"));
	printf("%d\n", isValid("([)]"));

	return 0;
}

~~~

**1.c++静态库头文件的内容会在c项目中展开，但是 c 语言不识别==extern "C"==,就需要配合条件编译 让extern "C"只能出现在c++项目中**

**2.条件编译使得extern "C"在c++静态库中生效，在c项目中不被编译，==（头文件在预处理阶段被展开）==**

**3.==调用c++的静态库就不能使用函数重载==**

~~~Cpp
#ifdef __cplusplus 
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif
EXTERN_C //头文件的内容在c项目中展开后 EXTERN_C并没有被定义 只留下两个大括号 这就是这种写法不通过的原因
{
	void StackInit(ST* ps);
	void StackDestroy(ST* ps);
	void StackPush(ST* ps, STDataType x);
	void StackPop(ST* ps);
	STDataType StackTop(ST* ps);
	int StackSize(ST* ps);
	bool StackEmpty(ST* ps);
}
~~~

**正确的写法 **   ==公司项目中的用法==

~~~Cpp
#ifdef __cplusplus //c++项目中默认定义的宏标识  区别c++程序还是c程序
extern "C" 
{  //前面部分定义出来 后面再补齐
#endif  

	void StackInit(ST* ps);
	void StackDestroy(ST* ps);
	void StackPush(ST* ps, STDataType x);
	void StackPop(ST* ps);
	STDataType StackTop(ST* ps);
	int StackSize(ST* ps);
	bool StackEmpty(ST* ps);
#ifdef __cplusplus
}   //这种写法是为了加收括号
#endif

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

EXTERN_C void StackInit(ST* ps);
EXTERN_C void StackDestroy(ST* ps);
EXTERN_C void StackPush(ST* ps, STDataType x);
EXTERN_C void StackPop(ST* ps);
EXTERN_C STDataType StackTop(ST* ps);
EXTERN_C int StackSize(ST* ps);
EXTERN_C bool StackEmpty(ST* ps);
~~~

#### 4.1图片展示

![image-20220307183456254](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220307183456254.png)

#### 4.2总结

![image-20220307183554908](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220307183554908.png)

## 三、内联函数

以inline修饰的函数叫做内联函数，编译时C++编译器会在调用内联函数的地方展开，没有函数压栈的开销， 内联函数提升程序运行的效率。

 ~~~Cpp
 // 调用函数，需要建立栈帧，栈帧中要保存一些寄存器，结束后又要恢复...
 // 可以看到这些都是有消耗的。
 // 对于频繁调用的小函数，能否优化一下？
 // C -- 宏
 
 int Add(int x, int y)
 {
 	int ret = x + y;
 	return ret;
 }
 
 /*int main()
 {
 	Add(1, 2);
 	Add(1, 2);
 	Add(1, 2);
 	Add(1, 2);
 	Add(1, 2);
 	Add(1, 2);
 	Add(1, 2);
 
 	return 0;
 }*/
 
 //  写一个两个数相加的宏 -- 技巧，记住宏原理是替换，你替换一下看看对不对
 //注释都是错误的写法
 //#define ADD(int x, int y) { return x + y;}
 //#define ADD(int x, int y) return x + y;
 //#define ADD(int x, int y) x + y;
 //#define ADD(x, y) x + y;
 //#define ADD(x, y) x + y
 //#define ADD(x, y) (x + y)
 #define ADD(x, y) ((x) + (y))
 
 int main()
 {
 	//cout << ADD(1, 2) << endl; // cout << 1 + 2; << endl; 
 	cout << ADD(3, 4) << endl;  // cout << 3 + 4 << endl;
 	cout << 10 * ADD(3, 4) << endl; // cout << 10*3+4 << endl;
 
 	int a = 0, b = 1;
 	cout << ADD(a | b, a&b) << endl; //cout << (a|b + a&b) << endl; 加号运算优先级更高
 
 	return 0;
 }
 
 // 有了inline, 我们就不需要用C的宏，因为宏很复杂，很容易出错
 //如上有很多错误的写法
 inline int Add(int x, int y)
 {
 	int ret = x + y;
 	return ret;
 }
 
 inline void Swap(int& a, int& b)
 {
 	int tmp = a;
 	a = b;
 	b = tmp;
 }
 
 int main()
 {
 	int ret = Add(1, 2);
 	cout << ret << endl;
 
 	int x = 0, y = 1;
 	Swap(x, y);
 
 	return 0;
 }
 ~~~

#### 3.1汇编展示

![image-20220307184942571](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220307184942571.png)

![image-20220307184612693](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220307184612693.png)

加了内联默认只在release下展开，release优化的太厉害看不出来，debug默认不展开，需要配置一下才能展开

![image-20220307192224736](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220307192224736.png)

![image-20220307192155265](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220307192155265.png)

#### 3.2结论

![image-20220307192345450](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220307192345450.png)

#### 3.3注意事项

![image-20220307192418476](C:\Users\李晓冬\AppData\Roaming\Typora\typora-user-images\image-20220307192418476.png)

#### 3.4宏的优缺点？ 

 优点： 1.增强代码的复用性。 2.提高性能。

 缺点： 1.不方便调试宏。（因为预编译阶段进行了替换） 

2.导致代码可读性差，可维护性差，容易误用。 3.没有类型安全的检查 。 

**C++有哪些技术替代宏？ **

1. 常量定义 换用const  
2. 2. 函数定义 换用内联函数

