#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#include <stack>
#include <queue>
#include <algorithm>

#include "Stack.h"
#include "Queue.h"

void test_op1()
{
	srand(time(0));
	const int N = 1000000;

	deque<int> dq;
	vector<int> v;

	for (int i = 0; i < N; ++i)
	{
		auto e = rand() + i;
		v.push_back(e);
		dq.push_back(e);
	}

	int begin1 = clock();
	sort(v.begin(), v.end());
	int end1 = clock();

	int begin2 = clock();
	sort(dq.begin(), dq.end());
	int end2 = clock();

	printf("vector:%d\n", end1 - begin1);
	printf("deque:%d\n", end2 - begin2);
}

void test_op2()
{
	srand(time(0));
	const int N = 1000000;

	deque<int> dq1;
	deque<int> dq2;

	for (int i = 0; i < N; ++i)
	{
		auto e = rand() + i;
		dq1.push_back(e);
		dq2.push_back(e);
	}

	int begin1 = clock();
	sort(dq1.begin(), dq1.end());
	int end1 = clock();

	int begin2 = clock();
	// 拷贝到vector
	vector<int> v(dq2.begin(), dq2.end());
	sort(v.begin(), v.end());
	dq2.assign(v.begin(), v.end());
	int end2 = clock();

	printf("deque sort:%d\n", end1 - begin1);
	printf("deque copy vector sort, copy back deque:%d\n", end2 - begin2);
}

void test_stack1()
{
	bit::stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}
void test_queue1()
{
	bit::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}
// 优先级队列
void test_priority_queue1()
{
	// 默认大的优先级高 底层是个大堆
	// priority_queue<int> pq;
	// 小堆 小于是大堆 大于是小堆
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(3);
	pq.push(1);
	pq.push(4);
	pq.push(2);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

	vector<int> v = {3, 1, 7, 4, 6, 3};
	// 升序
	sort(v.begin(), v.end());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	// 降序
	// greater<int> gt;
	// sort(v.begin(), v.end(), gt);
	sort(v.begin(), v.end(), greater<int>());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test_priority_queue2()
{
	// bit::priority_queue<int,vector<int>> pq;
	// bit::priority_queue<int,deque<int>> pq;
	// bit::priority_queue<int> pq;
	bit::priority_queue<int, vector<int>, bit::greater<int>> pq;
	pq.push(2);
	pq.push(1);
	pq.push(4);
	pq.push(3);
	pq.push(7);
	pq.push(8);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

class Date
{
public:
	friend ostream &operator<<(ostream &_cout, const Date &d);

	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year), _month(month), _day(day)
	{
	}
	bool operator<(const Date &d) const
	{
		return (_year < d._year) ||
			   (_year == d._year && _month < d._month) ||
			   (_year == d._year && _month == d._month && _day < d._day);
	}
	bool operator>(const Date &d) const
	{
		return (_year > d._year) ||
			   (_year == d._year && _month > d._month) ||
			   (_year == d._year && _month == d._month && _day > d._day);
	}

private:
	int _year;
	int _month;
	int _day;
};
ostream &operator<<(ostream &_cout, const Date &d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

struct GreaterPDate
{
	bool operator()(const Date *p1, const Date *p2)
	{
		return *p1 > *p2;
	}
};
void test_priority_queue3()
{
	bit::priority_queue<Date, vector<Date>, bit::greater<Date>> pq;
	Date d1(2025, 12, 7);
	pq.push(d1);
	pq.push(Date(2025, 12, 6));
	pq.push({2025, 12, 5});

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

	bit::priority_queue<Date *, vector<Date *>, GreaterPDate> pqptr;
	pqptr.push(new Date(2025, 12, 14));
	pqptr.push(new Date(2025, 12, 11));
	pqptr.push(new Date(2025, 12, 15));

	while (!pqptr.empty())
	{
		cout << *(pqptr.top()) << " ";
		pqptr.pop();
	}
	cout << endl;
}
void test_priority_queue4()
{
	bit::priority_queue<Date, vector<Date>, bit::greater<Date>> pq;
	Date d1(2025, 12, 7);
	pq.push(d1);
	pq.push(Date(2025, 12, 6));
	pq.push({2025, 12, 5});

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

	bit::priority_queue<Date *, vector<Date *>, GreaterPDate> pqptr;
	pqptr.push(new Date(2025, 12, 14));
	pqptr.push(new Date(2025, 12, 11));
	pqptr.push(new Date(2025, 12, 15));

	while (!pqptr.empty())
	{
		cout << *(pqptr.top()) << " ";
		pqptr.pop();
	}
	cout << endl;
}
// 仿函数
// template<class T>
// struct Less
//{
//	bool operator()(const T& x, const T& y)
//	{
//		return x < y;
//	}
//};
// int main()
//{
//	//test_stack1();
//	//test_queue1();
//	//test_priority_queue();
//	Less<int> lessfunc;
//	cout << lessfunc(1, 2) << endl;
//	cout << lessfunc.operator()(1, 2) << endl;
//	// 匿名对象
//	cout << Less<int>()(1, 2) << endl;
//	cout << Less<int>().operator()(1, 2) << endl;
//	return 0;
//}
int main()
{
	// test_stack1();
	// test_queue1();
	// test_priority_queue();
	// test_priority_queue2();
	// test_priority_queue3();
	return 0;
}