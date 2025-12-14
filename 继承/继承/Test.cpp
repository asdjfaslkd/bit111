#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
//基类
class Person
{
public:
	//构造函数
	Person(const string& name = "peter")
		:_name(name)
	{
		cout << "Person()" << endl;
	}
	//拷贝构造函数
	Person(const Person& p)
		:_name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}
	//赋值运算符重载函数
	Person& operator=(const Person& p)
	{
		cout << "Person& operator=(const Person& p)" << endl;
		if (this != &p)
		{
			_name = p._name;
		}
		return *this;
	}
	//析构函数
	~Person()
	{
		cout << "~Person()" << endl;
	}
private:
	string _name; //姓名
};
//派生类
class Student : public Person
{
public:
	//构造函数
	Student(const string& name, int id)
		//:Person(name) //调用基类的构造函数初始化基类的那一部分成员
		:Person(name)
		, _id(id) //初始化派生类的成员
	{
		cout << "Student()" << endl;
	}
	//拷贝构造函数
	Student(const Student& s)
		:Person(s) //调用基类的拷贝构造函数完成基类成员的拷贝构造
		, _id(s._id) //拷贝构造派生类的成员
	{
		cout << "Student(const Student& s)" << endl;
	}
	//赋值运算符重载函数
	Student& operator=(const Student& s)
	{
		cout << "Student& operator=(const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator=(s); //调用基类的operator=完成基类成员的赋值
			_id = s._id; //完成派生类成员的赋值
		}
		return *this;
	}
	//析构函数
	~Student()
	{
		cout << "~Student()" << endl;
		//派生类的析构函数会在被调用完成后自动调用基类的析构函数
	}
private:
	int _id; //学号
};

int main()
{
	Student st("xxxx", 1);

}

class Person
{
public:
	void Print()
	{
		cout << _name << endl;
	}
protected:
	string _name; // 姓名
private:
	int _age; // 年龄
};
//class Student : protected Person
//class Student : private Person
//class Student : public Person
//{
//protected:
//	int _stunum; // 学号
//};
//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex;  // 性别
//	int _age; // 年龄
//};

class Student : public Person
{
public:
	int _No; // 学号
};
void Test()
{
	Student sobj;
	// 1.子类对象可以赋值给父类对象/指针/引用
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;

	//2.基类对象不能赋值给派生类对象
	sobj = pobj;

	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
	pp = &sobj
		Student * ps1 = (Student*)pp; // 这种情况转换时可以的。
	ps1->_No = 10;

	pp = &pobj;
	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
		ps2->_No = 10;
}

class Person
{
public :
 Person(const char* name = "peter")
 : _name(name )
 {
 cout<<"Person()" <<endl;
 }
    
 Person(const Person& p)
 : _name(p._name)
 {
     cout<<"Person(const Person& p)" <<endl;
 }
    
 Person& operator=(const Person& p )
 {
 cout<<"Person operator=(const Person& p)"<< endl;
 if (this != &p)
 _name = p ._name;
        
 return *this ;
 }
    
 ~Person()
 {
 cout<<"~Person()" <<endl;
 }
protected :
 string _name ; // 姓名
};
class Student : public Person
{
public :
 Student(const char* name, int num)
 : Person(name )
 , _num(num )
 {
 cout<<"Student()" <<endl;
 }
 
 Student(const Student& s)
 : Person(s)
 , _num(s ._num)
 {
 cout<<"Student(const Student& s)" <<endl ;
 }
 
 Student& operator = (const Student& s )
 {
 cout<<"Student& operator= (const Student& s)"<< endl;
 if (this != &s)
 {
 Person::operator =(s);
 _num = s ._num;
 }
 return *this ;
 } 
 
 ~Student()
 {
 cout<<"~Student()" <<endl;
 }
protected :
 int _num ; //学号
};
void Test ()
{
 Student s1 ("jack", 18);
 Student s2 (s1);
 Student s3 ("rose", 17);
 s1 = s3 ;
}