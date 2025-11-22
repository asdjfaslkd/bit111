#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//class Time
//{
//public:
//
//	// 没有默认构造函数
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	//Date(int year = 1, int month = 1, int day = 1)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	void Print()
//	{
//		cout << _year << "_" << _month << "_" << _day << endl;
//	}
//private:
//	// 内置类型
//	int _year;
//	int _month;
//	int _day;
//
//	// 自定义类型
//	Time _t;
//};
//
//int main()
//{
//	Date d;
//	d.Print();
//
//	//Date d1(2025, 11, 13);
//	//d1.Print();
//	return 0;
//}

//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//
//	}
//private:
//	int _hour = 0;
//	int _minute = 11;
//	int _second = 20;
//};
//class Date
//{
//private:
//	// 缺省值
//	int _year=2025;
//	int _month=11;
//	int _day=13;
//	
//	Time _t;
//};
//
//int main()
//{
//	Date d;
//
//	return 0;
//}
//class Time
//{
//public:
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//	//Time() = default;
//	Time()
//	{
//		_hour = 1;
//		_mintue = 1;
//		_second = 1;
//	}
//	Time(const Time& t)
//	{
//		_hour = t._hour;
//		_mintue = t._mintue;
//		_second = t._second;
//
//	}
//private:
//	int _hour;
//	int _mintue;
//	int _second;
//};
//class Date
//{
//public:
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//	Date(int year = 2025, int month = 11, int day = 13)
//	{
//		cout << "Date()" << endl;
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d;
//
//	Date d1(1, 1, 1);
//	return 0;
//}
/////////////////////////////////////////////////////////
// 拷贝构造
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// Date d2(d1)
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;																							
//	}
//	void Print()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2025, 11, 13);
//	Date d2(d1);
//	d1.Print();
//	d2.Print();
//	return 0;
//}

// 值传递 会引发无限递归
//void func1(Date d)
//{
//
//}
//
//void func2(Date& rd)
//{
//
//}
//
//int main()
//{
//	Date d1(2024, 1, 28);
//	// C++规定自定义的类型都会调用拷贝构造
//	func1(&d1);
//	func2(d1);
//
//	return 0;
//}

//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (_array == NULL)
//		{
//			perror("malloc fail");
//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//	// Stack st2(st1)
//	Stack(const Stack& s)
//	{
//		DataType* tmp = (DataType*)malloc(sizeof(DataType) * s._capacity);
//		if (tmp == NULL)
//		{
//			perror("malloc fail");
//			return;
//		}
//		memcpy(tmp, s._array, sizeof(DataType) * s._size);
//		_array = tmp;
//		_size = s._size;
//		_capacity = s._capacity;
//	}
//	void push(const DataType& data)
//	{
//		_array[_size] = data;
//		_size++;
//	}
//	~Stack()
//	{
//		// 若数组不为空就free释放
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//class MyQueue
//{
//private:
//	Stack st1;
//	Stack st2;
//};
//int main()
//{
//	Stack st1;
//	Stack st2(st1);
//
//	MyQueue q1;
//	MyQueue q2(q1);
//
//	return 0;
//}


//class A {
//public:
//	A(int x) : _x(x) 
//	{
//		cout << "A(int) 构造临时对象" << endl;
//	}
//	A(const A& other) : _x(other._x) 
//	{
//		cout << "A(const A&) 拷贝构造" << endl;
//	}
//private:
//	int _x;
//};
//
//int main() {
//	A aa1 = 2;  // 禁用优化后输出：
//	// A(int) 构造临时对象
//	// A(const A&) 拷贝构造
//	return 0;
//}

//struct ListNode
//{
//	ListNode* _next;
//	int _val;
//
//	ListNode(int val)
//		:_next(nullptr)
//		, _val(val)
//	{}
//};
//
//struct ListNode* CreateListNode(int val)
//{
//	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
//	if (newnode == NULL)
//	{
//		perror("malloc fail");
//		return NULL;
//	}
//
//	newnode->_next = NULL;
//	newnode->_val = val;
//	return newnode;
//}
//
//// 创建的不带哨兵位
//ListNode* CreateList(int n)
//{
//	ListNode head(-1);  // 哨兵位
//
//	ListNode* tail = &head;
//	int val;
//	printf("请依次输入%d个节点的值：>", n);
//	for (size_t i = 0; i < n; i++)
//	{
//		cin >> val;
//		tail->_next = new ListNode(val);
//		tail = tail->_next;
//	}
//
//	return head._next;
//}
//
//void func()
//{
//	int n = 1;
//	while (1)
//	{
//		int* p = new int[1024 * 1024 * 100];
//		//int* p = (int*)malloc(1024 * 1024*4);
//
//		cout << n << "->" << p << endl;
//		++n;
//	}
//}
//
//int main()
//{
//	// 1、用法上，变简洁了
//	int* p0 = (int*)malloc(sizeof(int));
//	int* p1 = new int;
//	int* p2 = new int[10]; // new 10个int对象
//
//	// 2、可以控制初始化
//	int* p3 = new int(10); // new 1个int对象,初始化成10
//	int* p4 = new int[10]{ 1,2,3,4,5 };
//
//	// 3、自定义类型，开空间+构造函数
//	// 4、new失败了以后抛异常，不需要手动检查
//	ListNode* node1 = new ListNode(1);
//	ListNode* node2 = new ListNode(2);
//	ListNode* node3 = new ListNode(3);
//	//...
//	//ListNode* list1 = CreateList(5);
//
//	delete p3;
//	delete[] p4;
//	delete p1;
//	delete[] p2;
//
//	try
//	{
//		func();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}


//class Date
//{
//public:
//	// 构造函数
//	Date(in
// t year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	 //拷贝构造
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2025, 11, 15);
//	// 用已经存在的对象d1创建新对象d2
//	Date d2(d1);
//
//	return 0;
//}

//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_a = (int*)malloc(sizeof(int) * capacity);
//		_top = 0;
//		_capacity = capacity;
//	}
//	void Print()
//	{
//		cout << _a << endl;
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};
//int main()
//{
//	Stack st1;
//	st1.Print();
//	Stack st2(st1);
//	st2.Print();
//	return 0;
//}

//class Date
//{
//public:
//	// 构造函数
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{
//		cout << "Date(int year = 1, int month = 1, int day = 1)" << endl;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		cout << "Date(const Date& d)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2025, 11, 15);
//	// 用已经存在的对象d1创建新对象d2
//	Date d2(d1);
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a)
//	{
//		_a = a;
//		cout << "A(int a)" << endl;
//	}
//private:
//	int _a;
//};
//class B
//{
//public:
//	B(int b = 1)
//		:_aa(1)
//		,_b(b)
//	{
//		cout << "B()" << endl;
//	}
//private:
//	int _b;
//	A _aa;
//};
//
//int main()
//{
//
//	B s(1);
//	return 0;
//}

//class Time
//{
//public:
//	Time(int hour=1)
//	{
//		_hour = hour;
//	}
//private:
//	int _hour;
//};
//class Test
//{
//public:
//	Test(int hour)
//	{
//		Time t(hour);
//		_t = t;
//	}
//private:
//	Time _t;
//};

//int i = 0;
//class Test
//{
//public:
//	Test()
//		:_b(i++)
//		,_a(i++)
//	{}
//	void Pirnt()
//	{
//		cout << "_a:" << _a << endl;
//		cout << "_b:" << _b << endl;
//	}
//private:
//	int _a;
//	int _b;
//};
//int main()
//{
//	Test test;
//	// 打印结果_a=0,_b=1
//	// 初始化列表的初始化顺序和声明的顺序有关
//	test.Pirnt();
//	return 0;
//}

//class Date
//{
//public:
//	Date(int day = 1)
//		:_day(day)
//	{
//		cout << "Date(int day=1)" << endl;
//	}
//	Date(const Date& d)
//	{
//		_day = d._day;
//		cout << "Date(const Date& d)" << endl;
//	}
//	void Print()
//	{
//		cout << _day << endl;
//	}
//private:
//	int _day;
//};
//int main()
//{
//	//Date d1 = 15;
//	//d1.Print();
//	// 上面等价于下面
//	Date d1(12);
//	Date d2(d1);
//	d1.Print();
//	d2.Print();
//	return 0;
//}

//class Date
//{
//private:
//	static int a;
//};
//int main()
//{
//	cout << sizeof(Date) << endl;
//	return 0;
//}

//class Date
//{
//public:
//	static int a;
//};
//// 静态成员变量的定义初始化
//int Date::a = 0;
//int main()
//{
//
//	Date test;
//	// 通过类对象突破类域进行访问
//	cout << test.a << endl;
//	// 通过匿名对象突破类域进行访问
//	cout << Date().a << endl;
//	// 通过类名突破类域进行访问
//	cout << Date::a << endl;
//	return 0;
//}

//class Test
//{
//public:
//	static int Geta()
//	{
//		return a;
//	}
//private:
//	static int a;
//};
//int Test::a = 0;
//int main()
//{
//	Test test;
//	cout << test.Geta() << endl;
//	cout << Test().Geta() << endl;
//	cout << Test::Geta() << endl;
//	return 0;
//}

