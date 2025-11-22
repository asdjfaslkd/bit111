#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1);
	Date(const Date& d);
	// 运算符重载
	Date& operator=(const Date& d);
	bool operator==(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator!=(const Date& d);

	Date operator+(int day);
	Date& operator+=(int day);

	Date operator-(int day);
	Date& operator-=(int day);


	int GetMonthDay(int year, int month)
	{
		assert(month > 0 && month < 13);
		int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 || (year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)
		{
			return 29;
		}
		return monthDays[month];
	}
	void Print()	
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};