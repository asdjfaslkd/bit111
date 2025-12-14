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

class Person
{
public:
    virtual void BuyTicket()
    {
        cout << "买票-全价" << endl;
    }
    int _p = 1;
};
// 子类
class Student : public Person
{
public:
    virtual void BuyTicket()
    {
        cout << "买票-半价" << endl;
    }
    int _s = 2;
};

int main()
{
    Person Mike;
    Student Johnson;
    Johnson._p = 3;
    Person *p1 = &Mike;
    Person *p2 = &Johnson;
    p1->BuyTicket();
    p2->BuyTicket();
}