#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h"

void Test1()
{
	Date d1(2025, 11, 16);
	Date d2(d1);
	Date d3(2025, 1, 20);
	Date d4(2025, 12, 1);
	Date d5;

	cout << (d3 < d2) << endl;
	cout << (d3 == d5) << endl;
	cout << (d3 <= d4) << endl;
	cout << (d1 != d2) << endl;
}
void Test2()
{
	Date d1(2025, 11, 17);
	Date d2 = d1 + 10;
	Date d3 = (d1 += 20);
	d1.Print();
	d2.Print();
	d3.Print();
}
int main()
{
	//Test1();
	Test2();
	return 0;
}