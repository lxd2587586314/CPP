#include<iostream>
#include "Date.h"
using namespace std;

int Date::GetMonthDay(int year, int month)
{
	int MonthDayArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	// 365天 5小时+
	int day = MonthDayArray[month];
	//先判断月是不是二月 不是就没必要进来判断  小细节
	if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		day++;
	}

	return day;
}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;

	if (!(year >= 0
		&& (month > 0 && month < 13)
		&& (day > 0 && day <= GetMonthDay(year, month))))
	{
		cout << "非法日期";
		//this->Print(); 不仅可以访问成员变量 还能调用成员函数
		Print();
	}
}

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year && _month > d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Date& Date::operator+=(int day)
{
	_day += day;

	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
	    _month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
	}

	return *this;
}

Date& Date::operator++()
{
	*this += 1;

	return *this;
}

Date Date::operator+(int day) //后置++ 需要调用拷贝构造两次 所以建议用前置++
{
	Date ret(*this);
	//ret.operator+=(day);
	ret += day;

	return ret;
	//return ret += day; 一行代码返回
}

// d1++; 后置为了跟前置++，进行区分
// 增加一下参数占位，跟前置++,构成函数重载
Date Date::operator++(int)
{
	Date ret(*this);
	*this += 1;

	return ret;
}