#include <iostream>
using namespace std;

//struct Student
//{
//private:
//	char name[20];
//	int age;
//};
//
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		//year = year; //就近原则 形参
//		//Date::year = year; 指定类域
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		//Date* this2;
//		/*cout << year << '-';
//		cout << _month << '-';
//		cout << _day <<endl;*/
//		//*this = nullptr;
//
//		cout << _year << '-' << _month << '-' << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	
//};
//
//int main()
//{
//	Date d1;
//	d1.Init(2022, 1, 15);
//	d1.Print();
//
//	Date d2;
//	d2.Init(2022, 1, 16);
//	d2.Print();
//	//Student peng = { "zpw",18 };
//	//cout<<
//	return 0;
//}
// 

//class Date
//{
//public:
//	//void Init(Date* const this, int year, int month, int day)
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	//void Print(Date* const this)
//	void Print()
//	{
//		//this = nullptr; this指针不能被改变
//		cout << _year << '-' << _month << '-' << _day << endl;
//
//		// 一般情况，我们都不会像下面这样显示写
//		//	cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.Init(2022, 1, 15); // d1.Init(&d1, 2022, 1, 15);
//	d1.Print();           // d1.Print(&d1);
//
//	Date d2;
//	d2.Init(2022, 1, 16); // d1.Init(&d2, 2022, 1, 15);
//	d2.Print();           // d2.Print(&d2);
//
//	/*const int* p1 = nullptr; 权限的放大
//	int* p2 = nullptr;
//
//	p1 = p2;
//	p2 = p1;*/
//
//	return 0;
//}
//
//class A
//{
//public:
//
//	void Show()
//	{
//		cout << "Show()" << endl; //没有使用this指针
//	}
//private:
//	int _a;
//};
//
//class AA
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl; //解引用用this空指针
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	//A* pa = nullptr;
//	//pa->Show();
//	
//	AA* paa = nullptr; 
//	paa->PrintA();
//}

///////////////////////////////////////////////////////////////////////
//int main()
//{
//	Stack st;
//	// 忘记调用初始化
//
//	StackPush(&st, 1);
//	StackPush(&st, 1);
//	StackPush(&st, 1);
//
//	// 忘记调用销毁函数
//
//	return 0;
//}

//class Date
//{
//public:
//
//	/*Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}*/
//
//	/*Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	// 语法上无参和全缺省的可以同时存在
//	// 但是如果存在无参调用，就会存在二义性
//
//	/*Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}*/
//
//	// 推荐实现全缺省或者半缺省，因为比较好用
//	//Date(int year, int month = 1, int day = 1)
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1; //半缺省不属于默认构造函数 不能被调用
//	Date(2022);  //构造函数只有这两种使用方法
//	Date(2022, 1);
//	Date(2022, 1, 15);
//
//	return 0;
//}
//
//class A
//{
//public:
//	A()
//	{
//		cout << " A()" << endl;
//		_a = 0;
//	}
//
//	/*A(int a = 0)
//	{
//	cout << " A()" << endl;
//	_a = a;
//	}*/
//
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//
//private:
//	// C++里面把类型分为两类：内置类型(基本类型)，自定义类型
//	// 内置类型：int/char/double/指针/内置类型数组 等等
//	// 自定义类型：struct/class定义的类型
//
//	// 我们不写编译器默认生成构造函数，对于内置类型不做初始化处理
//	// 对于自定类型成员变量会去调用它的默认构造函数初始化，如果没有默认构造函数就会报错
//	// 任何一个类的默认构造函数就是--不用参数就可以调用。
//	// 任何一个类的默认构造函数有三个，全缺省、无参、我们不写编译器默认生成的。
//	int _year;
//	int _month;
//	int _day;
//
//	A _aa; //如果A的类里面没有默认构造函数，Date类默认生成的构造函数对_aa没办法处理
//};
//
//int main()
//{
//	Date d1;
//	//Date.Date(); 错误的调用
//
//	return 0;
//}


//class Date
//{
//public:
//	// 推荐实现全缺省或者半缺省，因为比较好用
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	~Date()
//	{
//		// Date类没有资源需要清理，所以Date不实现析构函数都是可以的
//		cout << "~Date()" << endl;
//		//栈上的资源函数栈帧结束编译器自己会清理
//      //并不是所有的类都需要资源清理 
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	Stack(size_t capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail\n" << endl;
//			exit(-1);
//		}
//
//		_top = 0;
//		_capacity = capacity;
//	}
//
//	void Push(int val)
//	{}
//
//	~Stack() 
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//};
//	 
// 
//class B
//{
//public:
//	//A(int a, int b = 0)
//	B(int a = 0, int b = 1)
//	{
//		cout << " A()" << endl;
//		_a = a;
//		_b = b;
//	}
//
//	/*A(int a = 0)
//	{
//	cout << " A()" << endl;
//	_a = a;
//	}*/
//private:
//	int _a;
//	int _b;
//};
// 
// 
//class Student
//{
//public:
//	Student()
//	{}
//private:
//
//};
// 
//int main()
//{
//	//Date d1; //半缺省构造函数也不能调用 不属于默认构造函数
//
//	//Date d2(2022, 1, 15);
//
//	Date d1; //d1先构造 d2后构造
//	Date d2(2022, 1, 15);
//
//	Stack s1; 
//	Stack s2(60);  //s2先析构， s1后析构
//
//	return 0;
//}

//class Date
//{
//public:
//	// 推荐实现全缺省或者半缺省，因为比较好用
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	~Date()
//	{
//		// Date类没有资源需要清理，所以Date不实现析构函数都是可以的
//		cout << "~Date()" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int)*capacity);
//		if (_a == nullptr)
//		{
//			cout << "malloc fail\n" << endl;
//			exit(-1);
//		}
//
//		_top = 0;
//		_capacity = capacity;
//	}
//
//	void Push(int x)
//	{}
//
//	// 如果我们不写默认生成析构函数和构造函数类似
//	// 对于内置类型不做处理
//	// 对于自定义类型回去调用它的析构函数
//  //
//	~Stack() //malloc 自己写析构
//	{
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//		cout << "~Stack" << endl;
//	}
//
//private:
//	int* _a;
//	size_t _top;
//	size_t _capacity;
//};
//
//
//// 两个栈实现一个队列
//class MyQueue { //体现出默认生成的构造析构函数的价值
//public:
//	// 默认生成构造函数和析构函数会对自定义类型成员调用他的构造和析构
//	void push(int x) {
//	
//	}
//private:
//
//	Stack PopST;
//	Stack PushST;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(2022, 1, 15);
//
//	Stack s1;
//	Stack s2(20);
//
//	MyQueue mq;
//
//	return 0;
//}

class A
{
public:
	A()
	{
		_aa = 0;
	}

	/*A(const A&)
	{
		cout << "A(const A&)" << endl;
	}*/
private:
	int _aa;
};

class Date
{
public:
	// 推荐实现全缺省或者半缺省，因为比较好用
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	////Date(const Date d)
	//Date(const Date& d)
	//{
	//	_year = d._year;
	//	//d._year = _year; // 加const防止被误改
	//	_month = d._month;
	//	_day = d._day;
	//}

	~Date()
	{
		// Date类没有资源需要清理，所以Date不实现析构函数都是可以的
		cout << "~Date()" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	A _aa;
};

class Stack
{
public:
	Stack(int capacity = 4)
	{
		_a = (int*)malloc(sizeof(int) * capacity);
		if (_a == nullptr)
		{
			cout << "malloc fail\n" << endl;
			exit(-1);
		}

		_top = 0;
		_capacity = capacity;
	}

	void Push(int x)
	{}

	// 如果我们不写默认生成析构函数和构造函数类似
	// 对于内置类型不做处理
	// 对于自定义类型回去调用它的析构函数
	~Stack()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
		cout << "~Stack" << endl;
	}

private:
	int* _a;
	size_t _top;
	size_t _capacity;
};

void f(Date& d) 
{

}

int main()
{
	Date d1(2022, 1, 15);
	f(d1); //传值传参需要调用拷贝构造

	// 拷贝复制
	Date d2(d1);

	Stack st1(10);

	// 拷贝复制
	Stack st2(st1);

	return 0;
}

//int main()
//{
//	int i = 1;
//	if (i <= 0)
//		printf("****\n");
//
//	else
//		printf("%%%%\n");
//	return 0;
//}