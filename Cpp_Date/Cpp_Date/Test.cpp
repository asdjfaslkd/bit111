#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h"

void Test1()
{
	Date d1(2025, 11, 14);
	Date d2(2024, 12, 13);
	cout << (d1 == d2) << endl;
}
void Test2()
{
	Date d1(2025, 11, 14);
	Date d2 = d1 + 10;
	d1.Print();
	d2.Print();

	Date d3 = d2 += 10;
	d3.Print();
	d2.Print();
}
void Test3()
{
	Date d1(2025, 11, 14);
	Date d2 = d1 - 10;
	d1.Print();
	d2.Print();
	Date d3 = d2 -= 60;
	d3.Print();
}
void Test4()
{
	Date d1(2025, 11, 14);
	Date d2(d1);
	d1.Print();
	d2.Print();
}
void Test5()
{
	Date d1(2025, 10, 24);
	Date d2(2024, 11, 3);
	Date d3(2024, 11, 3);
	d1 = d2 = d3;
	d1.Print();
}
int main()
{
	Test5();
	return 0;
}