#pragma once

#include <assert.h>
namespace bit
{
    template <class T>
    struct ListNode
    {
        ListNode<T> *_next;
        ListNode<T> *_prev;
        T _date;

        ListNode(const T& x = T())
            : _next(nullptr)
            , _prev(nullptr)
            , _date(x)
        {}
    };

    template <class T>
    struct ListIterator
    {
        typedef ListNode<T> Node;
        typedef ListIterator<T> Self;
        Node *_node;
        ListIterator(Node *node)
            : _node(node)
        {}

        // *it
        T &operator*()
        {
            return _node->_date;
        }
        // ++it
        Self &operator++()
        {
            _node = _node->_next;
            return *this;
        }
        // it++
        Self operator++(int)
        {
            Self tmp(*this);
            _node = _node->_next;
            return tmp;
        }
        Self &operator--()
        {
            _node = _node->_prev;
            return *this;
        }
        // it++
        Self operator--(int)
        {
            Self tmp(*this);
            _node = _node->_prev;
            return tmp;
        }

        bool operator!=(const Self &it)
        {
            return _node != it._node;
        }
        bool operator==(const Self &it)
        {
            return _node == it._node;
        }
    };

    template <class T>
    class list
    {
        typedef ListNode<T> Node;

    public:
        typedef ListIterator<T> iterator;

        iterator begin()
        {
            return iterator(_head->_next);
        }
        iterator end()
        {
            return iterator(_head);
        }
        list()
        {
            _head = new Node;
            _head->_next = _head;
            _head->_prev = _head;
        }
        void push_back(const T &x)
        {
            Node *newnode = new Node(x);
            Node *tail = _head->_prev;

            tail->_next = newnode;
            newnode->_prev = tail;
            newnode->_next = _head;
            _head->_prev = newnode;
        }

    private:
        Node *_head;
    };

    void test_list1()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);

        list<int>::iterator it = lt.begin();
        while (it != lt.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }
}