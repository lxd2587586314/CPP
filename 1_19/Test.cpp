#include<iostream>
//using namespace std;
using std::cout;
using std::endl;

class A
{
public:
	A(int a)
	{
		_a = a;
	}
private:
	int _a;
};

class Date
{
public:
	Date(int year, int month, int day, int i)
		:_N(10)
		, _ref(i)
		, _aa(-1)
	{
		//  error C2166: 左值指定 const 对象
		// 这里报错说明到构造函数体内时，成员变量已经定义出来了
		//_N = 10;

		_year = year;
		_month = month;
		_day = day;
	}

	// 初始化列表 - 成员变量定义的地方 
	/*Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
		, _N(10)
	{}*/

private:
	int _year;  // 声明
	int _month;
	int _day;

	const int _N;  // const
	int& _ref;     // 引用
	A _aa;         // 没有默认构造函数的自定义类型成员变量
	// 总结一下：
	// 1、初始化列表 - 成员变量定义的地方
	// 2、const、引用、没有默认构造函数的自定义类型成员变量必须在初始化列表初始化，因为他们都必须在定义的时候初始化
	// 3、对于像其他类型成员变量，如int year、int _month,在哪初始化都可以
};

int main()
{
	int i = 0;
	Date d1(2022, 1, 19, i); // 对象定义/对象实例化

	Date d2(2021, 1, 19, i); // 对象定义/对象实例化

	// int i;
	// 常量必须在定义的时候初始化
	// const int j = 0;

	return 0;
}
