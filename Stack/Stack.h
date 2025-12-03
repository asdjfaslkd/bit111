#pragma once
#include <vector>
#include <list>

namespace bit
{
    /*template<class T>
    class stack
    {
    private:
        T* _a;
        int _top;
        int _capacity;
    };*/

    // 设计模式
    // 适配器模式 -- 转换
    // stack<int, vector<int>> st1;
    // stack<int, list<int>> st2;

    template <class T, class Container = vector<T>>
    class stack
    {
    public:
        void push(const T &x)
        {
            _con.push_back(x);
        }

        void pop()
        {
            _con.pop_back();
        }

        size_t size()
        {
            return _con.size();
        }

        bool empty()
        {
            return _con.empty();
        }

        const T &top()
        {
            return _con.back();
        }

    private:
        Container _con;
    };
}