#include<iostream>
#include "Date.h"
using namespace std;

int Date::GetMonthDay(int year, int month)
{
	int MonthDayArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	int day = MonthDayArray[month];

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

Date Date::operator+(int day)
{
	Date ret(*this);
	ret += day;

	return ret;
}

Date& Date::operator++()
{
	*this += 1;

	return *this;
}

// d1++; 后置为了跟前置++，进行区分
// 增加一下参数占位，跟前置++,构成函数重载
Date Date::operator++(int)
{
	Date ret(*this);
	*this += 1;

	return ret;
}