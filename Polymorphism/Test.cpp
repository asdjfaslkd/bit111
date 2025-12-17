#include <iostream>
using namespace std;

// class Person
// {
// public:
//     // 父类的虚函数
//     virtual void BuyTicket() { cout << "买票->全价" << endl; }
// };
// class Student : public Person
// {
// public:
//     // 子类的虚函数重写了父类的虚函数
//     // 派生类的虚函数不加virtual 也可以构成重写
//     //
//     virtual void BuyTicket() { cout << "秒票->半价" << endl; }
// };
// void Func(Person &p)
// {
//     p.BuyTicket();
// }
// void Func(Person *p)
// {
//     // 通过父类的引用调用虚函数
//     p->BuyTicket();
// }

// int main()
// {
//     Person p;
//     Student st;

//     Func(p);
//     Func(st);

//     Func(&p);
//     Func(&st);
//     return 0;
// }

// 虚函数重写的两个例外：
//  斜变(基类与派生类虚函数的返回值不一样)

// 基类
// class A
// {
// };
// class B : public A
// {
// };

// class Person
// {
// public:
//     virtual A *func()
//     {
//         cout << "A* Person::func()" << endl;
//         return nullptr;
//     }
// };
// class Student : public Person
// {
// public:
//     virtual B *func()
//     {
//         cout << "B* Student::func()" << endl;
//         return nullptr;
//     }
// };
// // 通过父类Person指针调用虚函数func
// // 父类指针指向的父类对象 则调用父类的虚函数
// // 父类指针指向的子类对象 则调用子类的虚函数
// int main()
// {
//     Person p;
//     Student st;

//     Person *ptr1 = &p;  // 父类指针指向父类对象
//     Person *ptr2 = &st; // 父类指针指向子类对象

//     ptr1->func(); // 调用的父类虚函数 A* Person::func()
//     ptr2->func(); // 调用的子类虚函数 B* Student::func()

//     return 0;
// }

// 析构函数的重写(基类与派生类析构函数的名字不同)
// 如果基类的析构函数为虚函数 那么派生类只要定义 不论加不加virtual关键字 都构成重写

// class Person
// {
// public:
//     virtual ~Person()
//     {
//         cout << "~Person()" << endl;
//     }
// };
// class Student : public Person
// {
// public:
//     virtual ~Student()
//     {
//         cout << "~Student()" << endl;
//     }
// };

// int main()
// {
//     // 分别new一个父类对象和子类对象，并均用父类指针指向它们
//     Person *p1 = new Person;
//     Person *p2 = new Student;

//     delete p1;
//     delete p2;
//     return 0;
// }

// class Person
// {
// public:
//     virtual void BuyTicket()
//     {
//         cout<<"买票->全价"<<endl;
//     }
// };
// class Student:public Person
// {
// public:
//     // 子类完成父类虚函数的重写 编译通过
//     virtual void BuyTicket()
//     {
//         cout<<"买票->半价"<<endl;
//     }
// };
// class Soldier:public Person
// {
// public:
//     // 子类没有完成父类虚函数的重写 编译报错
//     // virtual void BuyTicket(int i) override
//     // {
//     //     cout<<"优先->买票"<<endl;
//     // }
// };

// class Base
// {
// public:
//     virtual void func1()
//     {
//         cout << "func1()" << endl;
//     }

// private:
//     int _a = 1;
//     char _b = 'c';
// };
// int main()
// {
//     Base b;
//     // 32位机器下结果为12
//     cout << sizeof(b) << endl;

//     return 0;
// }

// 下面Base类当中有三个成员函数
// 其中Func1和Func2是虚函数，Func3是普通成员函数，子类Derive当中仅对父类的Func1函数进行了重写
// 父类
// class Base
// {
// public:
//     // 虚函数
//     virtual void Func1()
//     {
//         cout << "Base::Func1()" << endl;
//     }
//     // 虚函数
//     virtual void Func2()
//     {
//         cout << "Base::Func2()" << endl;
//     }
//     // 普通成员函数
//     void Func3()
//     {
//         cout << "Base::Func3()" << endl;
//     }

// private:
//     int _b = 1;
// };
// // 子类
// class Derive : public Base
// {
// public:
//     // 重写虚函数Func1
//     virtual void Func1()
//     {
//         cout << "Derive::Func1()" << endl;
//     }

// private:
//     int _d = 2;
// };
// int main()
// {
//     Base b;
//     Derive d;
//     return 0;
// }

// class Person
// {
// public:
//     virtual void BuyTicket()
//     {
//         cout << "买票-全价" << endl;
//     }
//     int _p = 1;
// };
// // 子类
// class Student : public Person
// {
// public:
//     virtual void BuyTicket()
//     {
//         cout << "买票-半价" << endl;
//     }
//     int _s = 2;
// };

// int main()
// {
//     Person Mike;
//     Student Johnson;
//     Johnson._p = 3;
//     Person *p1 = &Mike;
//     Person *p2 = &Johnson;
//     p1->BuyTicket();
//     p2->BuyTicket();
// }

// 父类
// class Person
// {
// public:
//     void Print()
//     {
//         cout << "name:" << _name << endl;
//         cout << "age:" << _age << endl;
//     }

// protected:
//     string _name="张三";
//     int _age=18;
// };

// // 子类
// class Student:public Person
// {
// protected:
//     int _stuid;
// };

// class Teacher:public Person
// {
// protected:
//     int _jobid;
// };

// class Person
// {
// private:
//     string _name="张三";
// };

// class Student:public Person
// {
// public:
//     void Print()
//     {
//         //在派生类当中访问基类的private成员，error!
//         cout<<"name:"<<_name<<endl;
//     }
// protected:
//     int _stuid;
// };

// //基类
// class Person
// {
// protected:
// 	string _name; //姓名
// 	string _sex;  //性别
// 	int _age;     //年龄
// };
// //派生类
// class Student : public Person
// {
// protected:
// 	int _stuid;   //学号
// };

// int main()
// {
//     Student s;
//     Person p = s;     //派生类对象赋值给基类对象
//     Person* ptr = &s; //派生类对象赋值给基类指针
//     Person& ref = s;  //派生类对象赋值给基类引用

//     return 0;
// }

// 父类
// class Person
// {
// protected:
//     int _num = 111;
// };
// // 子类
// class Student : public Person
// {
// public:
//     void func()
//     {
//         cout << "_num:" << Person::_num << endl;
//     }

// protected:
//     int _num = 999;
// };

// int main()
// {
//     Student st;
//     st.func();
//     return 0;
// }

// 父类
// class Person
// {
// public:
//     void fun(int x)
//     {
//         cout << x << endl;
//     }
// };
// // 子类
// class Student : public Person
// {
// public:
//     void fun(double x)
//     {
//         cout << x << endl;
//     }
// };
// int main()
// {
//     Student s;
//     s.fun(3.14);       // 直接调用子类当中的成员函数fun
//     s.Person::fun(20); // 指定调用父类当中的成员函数fun
//     return 0;
// }

// class Person
// {
// public:
//     // 构造函数
//     Person(const string &name = "zhangsan")
//         : _name(name)
//     {
//         cout << "Person()" << endl;
//     }
//     // 拷贝构造
//     Person(const Person &P)
//         : _name(P._name)
//     {
//         cout << "Person(const Person& P)" << endl;
//     }
//     // 赋值运算符重载
//     Person &operator=(const Person &P)
//     {
//         cout << "Person& operator=(const Person& p)" << endl;
//         if (this != &P)
//         {
//             _name = P._name;
//         }
//         return *this;
//     }
//     // 析构函数
//     ~Person()
//     {
//         cout << "~Person()" << endl;
//     }

// private:
//     string _name;
// };

// class Student : public Person
// {
// public:
//     // 构造函数
//     Student(const string &name, int id)
//         : Person(name) // 调用基类的构造函数初始化基类的那一部分
//           ,
//           _stuid(id) // 初始化派生类的成员
//     {
//         cout << "Student()" << endl;
//     }
//     // 拷贝构造
//     Student(const Student &s)
//         : Person(s), _stuid(s._stuid)
//     {
//         cout<<"Student(const Student &s)"<<endl;
//     }
//     // 赋值运算符重载
//     Student& operator=(const Student& s)
//     {
//         cout<<"Student& operator=(const Student& s)"<<endl;
//         if(this!=&s)
//         {
//             Person::operator=(s);// 调用基类的operator=完成基类部分成员的赋值
//             _stuid=s._stuid;
//         }
//         return *this;
//     }
//     //析构函数
// 	~Student()
// 	{
// 		cout << "~Student()" << endl;
// 		//派生类的析构函数会在被调用完成后自动调用基类的析构函数
// 	}

// private:
//     int _stuid;
// };

// class Student;
// class Person
// {
// public:
//     friend void Display(const Person &p, const Student &s);

// protected:
//     string _name; // 姓名
// };
// class Student : public Person
// {
// public:
//     friend void Display(const Person &p, const Student &s);

// protected:
//     int _id;
// };
// void Display(const Person &p, const Student &s)
// {
//     cout << p._name << endl; // 可以访问
//     cout << s._id << endl;   // 无法访问 在派生类中加了友元就可以访问
// }
// int main()
// {
//     Person p;
//     Student s;
//     Display(p, s);
//     return 0;
// }

// class Person
// {
// public:
//     // 构造函数
//     Person()
//     {
//         _count++;
//     }
//     // 拷贝构造
//     Person(const Person &p)
//     {
//         _count++;
//     }

// protected:
//     string _name; // 姓名

// public:
//     static int _count;
// };

// int Person::_count = 0;
// // 派生类
// class Student : public Person
// {
// protected:
//     int _id; // 学号
// };

// // 派生类
// class Graduate : public Person
// {
// protected:
//     string _seminarCourse; // 研究科目
// };

// int main()
// {
//     Student s1;
//     Student s2(s1);
//     Student s3;
//     Graduate s4;
//     cout << Person::_count << endl;  // 4
//     cout << Student::_count << endl; // 4

//     cout << &Person::_count << endl;
//     cout << &Student::_count << endl;

//     return 0;
// }

// 基类
// class Person
// {
// public:
//     string _name; // 姓名
// };

// // 派生类
// class Student : public Person
// {
// protected:
//     int _num; // 学号
// };

// // 派生类
// class Teacher : public Person
// {
// protected:
//     int _id; // 职工编号
// };

// // 派生类
// // 多继承
// class Assistant : public Student, public Teacher
// {
// protected:
//     string _majorCourse; // 主修课程
// };

// int main()
// {
//     Assistant a;
//     // a._name = "peter"; // 二义性：无法明确知道要访问哪一个_name

//     // 显示指定访问哪个父类的成员
//     a.Student::_name = "张同学";
//     a.Teacher::_name = "王老师";

//     return 0;
// }
