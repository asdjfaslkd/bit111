#pragma once 

namespace bit
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _date;

		ListNode(const T& x = T())
			:_next(nullptr)
			,_prev(nullptr)
			,_date(x)
		{}
	};
	template<class T,class Ref,class Ptr>
	struct list_iterator
	{
		typedef ListNode<T> Node;
		typedef list_iterator<T, Ref, Ptr> self;
		Node* _node;
		list_iterator(Node* node)
			:_node(node)
		{}
		// ++it
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		// it++
		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		// --it
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		// it--
		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		// ==
		bool operator==(const self& it)
		{
			return _node == it._node;
		}
		// !=
		bool operator!=(const self& it)
		{
			return _node != it._node;
		}
		// *it
		Ref operator*()
		{
			return _node->_date;//返回结点指针所指结点的数据
		}
		// ->
		Ptr operator->()
		{
			return &_node->_date;//返回结点指针所指结点的数据的地址
		}
	};
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			//返回使用头结点后一个结点的地址构造出来的普通迭代器
			return iterator(_head->_next);
		}
		iterator end()
		{
			//返回使用头结点的地址构造出来的普通迭代器
			return iterator(_head);
		}
		const_iterator begin() const
		{
			return _head->_next;
		}

		const_iterator end() const
		{
			return const_iterator(_head->_next);
		}

		list()
		{
			_head = new Node;// 为头结点申请一块空间
			_head->_next = _head;// 让头结点的后继指向自己
			_head->_prev = _head;// 让头结点的前驱指向自己
		}
		void push_back(const T& x)
		{
			Node* newnode = new Node(x);
			Node* tail = _head->_prev;

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}
	private:
		Node* _head;
	};
	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}