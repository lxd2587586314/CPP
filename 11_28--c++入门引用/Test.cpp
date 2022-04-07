// 11_28.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "SList.h"
using namespace std;

//int main()
//{
//    std::cout << "Hello World!\n";
//    // 引用定义
//    int a = 10;
//    int& b = a;
//    //取地址
//    int* p = &b;
//    cout << sizeof(b) << endl;
//}

//int main()
//{
//    int arr[20] = { 0,1,2,3,4,5,6,7,8,9,10};
//    cout << arr[5] << endl;
//
//    return 0;
//}

//int main()
//{
//	int a = 10;
//	int& b = a;
//	
//	a = 20;
//	b = 30;
//	cout << b << endl;
//	cout << a << endl;
//	return 0;
//}

//int main()
//{
//	 //1、引用在**定义时必须初始化**
//	//int a = 10;
//	//int& b;
//
//	//2、一个变量可以有多个引用
//	int a = 10;
//	int& b = a;
//	int& c = a;
//	int& d = b;
//	double d = 1.1;//别名不可以和其他变量正式名冲突
//	
//	// 3、引用一旦引用一个实体，再不能引用其他实体
//	int a = 10;
//	int& b = a;
//
//	int c = 20;
//	// 1、这里是让b变成c的别名呢？ 否
//	// 2、还是把c赋值给b？ 是
//	b = c;
//	
//	//int* p1 = &a;
//	//p1 = &c; //指针可以改变指向
//	return 0;
//}

// 1、引用做参数
// _Z4swapii
void Swap(int* p1, int* p2)//传地址
{
	int* tmp = p1;
	p1 = p2;
	p2 = tmp;
}

// _Z4swapriri
void Swap(int& r1, int& r2)//传引用 引用形参声明
{
	int tmp = r1;
	r1 = r2;
	r2 = tmp;
}

//// _Z4swapii
//void Swap(int r1, int r2)   // 传值
//{
//	int tmp = r1;
//	r1 = r2;
//	r2 = tmp;
//}

// 他们三个构成函数重载
// 但是swap(x, y);调用时存在歧义，他不知道调用，传值还是传引用
// 类似以前讲的这个,他们构成重载，但是存在歧义
// void f();
// void f(int x = 0, int y = 0);

int main()
{
	//声明定义一起
	int x = 0, y = 1;
	Swap(&x, &y); 
	Swap(x, y); //传递实参引用定义

	return 0;
}

int* singleNumbers(int* nums, int numsSize, int& returnSize) {
	//int* singleNumbers(int* nums, int numsSize, int* returnSize){
	int* a = (int*)malloc(sizeof(int) * 2);

	//...

	//*returnSize = 2;
	returnSize = 2;
	return a;
}

int TestList()
{
	SLTNode* plist = NULL;
	SListPushBack(plist, 1);
	SListPushBack(plist, 2);
	SListPushBack(plist, 3);
	SListPushBack(plist, 4);
	SListPushFront(plist, 5);
	SListPushFront(plist, 6);
	SListPushFront(plist, 7);

	SListPrint(plist);

	int a = 10;
	int& b = a;

	int* p1 = &a;
	int*& p2 = p1;

	return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	char val;
};

//struct TreeNode* CreateTree(char* str, int* pi)
struct TreeNode* CreateTree(char* str, int& i)
{
	if (str[i] == '#')
	{
		(i)++;
		return NULL;
	}

	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = str[i++];
	root->left = CreateTree(str, i);
	root->right = CreateTree(str, i);

	return root;
}

void InOrder(struct TreeNode* root)
{
	if (root == NULL)
		return;

	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}

//int main()
//{
//	char str[100];
//	while (scanf("%s", str) != EOF)
//	{
//		int j = 0;
//		struct TreeNode* root = CreateTree(str, j);
//		InOrder(root);
//	}
//
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////
// 传值返回值
//int Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int ret = Add(1, 2);
//	cout << ret << endl;
//	return 0;
//}

// 传引用返回
//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(1, 2);
//	cout << ret << endl;
//	//Add(10, 20);
//	printf("11111111111111111111111111111111111111\n");
//	cout << ret << endl;
//
//	return 0;
//}

#include <time.h>
struct A { int a[10000]; };

A a;
// 值返回 -- 每次拷贝40000byte
A TestFunc1() { return a; }

// 引用返回 -- 没有拷贝
A& TestFunc2() { return a; }

void TestReturnByRefOrValue()
{
	// 以值作为函数的返回值类型
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();

	// 以引用作为函数的返回值类型
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();

	// 计算两个函数运算完成之后的时间
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}

void TestFunc1(A a) {}

void TestFunc2(A& a) {}

void TestRefAndValue()
{
	A a;
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc1(a);
	size_t end1 = clock();

	// 以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc2(a);
	size_t end2 = clock();

	// 分别计算两个函数运行结束后的时间
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}
