#include <iostream>
#include <assert.h>
using namespace std;

// 对比一下C++和C定义类别一些区别和联系  以Stack
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST, Stack;

void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
STDataType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);

// C的库
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0; // ps->top = -1;
	ps->capacity = 0;
}

void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}

		ps->a = tmp;
		ps->capacity = newCapacity;
	}

	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}

int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

bool StackEmpty(ST* ps)
{
	assert(ps);

	/*if (ps->top == 0)
	{
	return true;
	}
	else
	{
	return false;
	}*/
	return ps->top == 0;
}

void TestStack_C()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);

	//Stack copy = st;

	//printf("%d\n", st.a[st.top]);
	StackDestroy(&st);

	//StackDestroy(&copy);
}

// C++ / C Plus Plus
class StackCPP
{
public:
	StackCPP()
	{}

	// 拷贝构造
	// 拷贝赋值

	void Push(int x)
	{}

	int Top()
	{
		// ...
		return 0;
	}

	~StackCPP()
	{}
private:
	int* _a;
	int _top;
	int _capacity;
};

void TestStack_CPP()
{
	StackCPP st;
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
}

//int main()
//{
//	TestStack_C();
//	TestStack_CPP();
//
//	return 0;
//}

int f(int n)
{
	if (n <= 1)
		return n;

	return f(n - 1) + n;
}

//int main()
//{
//	/*while (1)
//	{
//	cout << "hello bit" << endl;
//	}*/
//
//	cout << f(10000) << endl;
//
//	return 0;
//}

int main()
{
	// 动态申请int和5个int数组
	// 总结 malloc/free  和 new/delete 对于内置类型没有本质区别，只有用法上的区别
	int* p1 = (int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int)*5);

	int* p3 = new int;
	//int* p3 = new int(5);
	// C++98不支持初始化new的数组, C++11支持用{}列表初始化
	int* p4 = new int[5];
	//int* p4 = new int[5]{1,2};

	free(p1);
	free(p2);
	delete p3;
	delete[] p4;

	p1 = nullptr;
	p2 = nullptr;
	p3 = nullptr;
	p4 = nullptr;

	return 0;
}