#include<iostream>
using namespace std;
#include "Date.h"
//class Date
//{
//public:
//
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
////private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//// 函数名 operator操作符
//// 返回类型 看操作符运算后返回值是什么
//// 参数，操作符有几个操作数，他就有几个参数
////
////int operator-(const Date& d1, const Date& d2);
////传参建议用上述形式，const可以接受任意类型对象，普通对象传给const是权限的缩小
////传引用可以提高效率，减少拷贝
////罗列出可以列出的true的情况，把未知的可能性多的一面放到另一面
////由于定义到类外面，成员变量私有不能访问。
////三种解决办法 1.类的私有变量公开，不合适破坏了封装性 
////             2.类里面写一个GetYear GetMonth函数来替换
////			   3.定义在类里面
////             4.友元函数  也会破坏封装性相对私有公开开的口更小一点
//
// bool operator>(const Date& d1, const Date& d2)
//{
//	if (d1._year > d2._year)
//	{
//		return true;
//	}
//
//	else if (d1._year == d2._year && d1._month > d2._month)
//	{
//		return true;
//	}
//
//	else if (d1._year == d2._year && d1._month == d2._month && d1._day > d2._day)
//	{
//		return true;
//	}
//
//	else
//	{
//		return false;
//	}
//}
//
//int main()
//{
//	Date d1(2022, 1, 16);
//	Date d2(2022, 1, 31);
//	Date d3(2022, 2, 26);
//
//	// 默认情况C++是不支持自定义类型对象使用运算符
//	//d1 > d2; // -》operator>(d1, d2) 编译器转换成对应代码
//	//cout << operator>(d1, d2) << endl;
//
//	cout << (d1 > d2) << endl; //流插入操作符运算优先级比>高
//	cout << operator>(d1, d2) << endl; //为什么不想这样去用 原因是增强程序可读性 
//	//编译器报错有时候需要屏蔽一部分信息，其次看报错第一条，后面报错可能会误导你
//	//int day1 = d2 - d1;
//	//int day2 = d3 - d1;
//
//	return 0;
//}

//class Date
//{
//public:
//
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//  //罗列出可以列出的true的情况，把未知的可能性多的一面放到另一面
// 
// //bool operator>(const Date& d1, const Date& d2)  //三个参数 参数太多
// //bool operator>(const Date& d) //成员函数默认多一个参数 : this指针 
// //d1.operator>(d2); d1传给this 
// //bool operator>(const Date& d) // bool operator>(Date* const this, const Date& d)
//	{
//		if (_year > d._year)
//		{
//			return true;
//		}
//
//		else if (_year == d._year && _month > d._month)
//		{
//			return true;
//		}
//
//		else if (_year == d._year && _month == d._month && _day > d._day)
//		{
//			return true;
//		}
//
//		else
//		{
//			return false;
//		}
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//// 函数名 operator操作符
//// 返回类型 看操作符运算后返回值是什么  
//// 可以是内置类型也可以是自定义类型
//// 参数，操作符有几个操作数，他就有几个参数
////
////int operator-(const Date& d1, const Date& d2);
////全局和成员都定义构成函数重载，调用的是成员函数
//bool operator>(const Date& d1, const Date& d2)
//{
//	if (d1._year > d2._year)
//	{
//		return true;
//	}
//
//	else if (d1._year == d2._year && d1._month > d2._month)
//	{
//		return true;
//	}
//
//	else if (d1._year == d2._year && d1._month == d2._month && d1._day > d2._day)
//	{
//		return true;
//	}
//
//	else
//	{
//		return false;
//	}
//}
// 
//int main()
//{
//	Date d1(2022, 1, 16);
//	Date d2(2022, 1, 31);
//	Date d3(2022, 2, 26);
//
//	cout<<(d1 > d2)<<endl;
//	d1.operator>(d2);// 编译器转化为 d1.operator>(d2); 
//
//	return 0;
//}

//class Date
//{
//public:
//
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//
//	// d1 = d3;
//	// d1 = d1;
//	//Date operator=(const Date& d) 传返回值也是一次拷贝构造 用引用就减少调用拷贝构造
//	Date operator=(const Date& d)
//	{
//		// 极端情况下自己给自己赋值就可以不同处理了，直接判断一下跳过
//		//if (*this != d) //对象的比较就需要重载！=调用函数来比较 代价太大
//		if (this != &d) //不允许犯的错误采用assert
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		//出了作用域生命周期还在就可以用引用返回减少拷贝
//		return *this;
//	}
//
//	// d1.operator>(d2);
//	bool operator>(const Date& d) // bool operator>(Date* const this, const Date& d)
//	{
//		if (_year > d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month > d._month)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day > d._day)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
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
//	Date d1(2022, 1, 16);
//	Date d2(2022, 1, 31);
//	Date d3(2022, 2, 26);
//
//	// 一个已经存在的对象拷贝初始化一个马上创建实例化的对象
//	Date d4(d1);  // 拷贝构造
//	Date d5 = d1; // 拷贝构造
//
//	// 两个已经存在的对象之间进行赋值拷贝
//	d2 = d1 = d3; // d1.operator=(d3)
//	d1 = d3; // d1.operator=(d3)
//
//	d1 = d1;//
//
//	int i, j, k;
//	i = j = k = 10;//从右往左进行赋值
//
//	return 0;
//}

void TestDate1()
{
	Date d1;
	Date d2(2022, 1, 16);
	d1.Print();
	d2.Print();

	Date d3(2022, 13, 15);
	d3.Print();

	Date d4(2022, 2, 29);
	d4.Print();

	Date d5(2020, 2, 29);
	d5.Print();

	Date d6(2000, 2, 29);
	d6.Print();
}

void TestDate2()
{
	Date d1(2022, 1, 16);
	Date ret = d1 + 100;
	ret.Print();
	d1.Print();

	d1 += 100;
	d1.Print();

}

void TestDate3()
{
	Date d1(2022, 1, 16);
	Date ret = d1 + 100;
	ret.Print();

	d1 += 100;
	d1.Print();

	Date ret1 = d1++;  // d1.operator++(&d1, 0);
	Date ret2 = ++d1;  // d1.operator++(&d1);
}

int main()
{
	//TestDate1();
	//TestDate2();
	TestDate3();
	return 0;
}