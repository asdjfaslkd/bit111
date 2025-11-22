#pragma once

#include<assert.h>
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		//// 无参构造
		//string()
		//	: _str(new char[1])
		//	,_size(0)
		//	,_capacity(0)
		//{
		//	_str[0] = '\0';
		//}
		//// 带参构造
		//string(const char* str)
		//	:_size(strlen(str))
		//	,_str(new char[strlen(str) + 1])
		//	,_capacity(strlen(str))
		//{
		//	strcpy(_str, str);
		//}
		// 半缺省
		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		// 析构
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		const char* c_str() const
		{
			return _str;
		}
		// 遍历
		size_t size() const
		{
			return _size;
		}
		size_t capacity() const
		{
			return _capacity;
		}
		char& operator[](size_t pos)
		{
			return _str[pos];
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	void Test_string1()
	{
		string s1("hello world");
		string s2;
		const string s3("hello world");
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << s3.c_str() << endl;

		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;
		for (size_t i = 0; i < s1.size(); i++)
		{
			s1[i]++;
			cout << s1[i] << " ";
		}
		cout << endl;
		for (size_t i = 0; i < s3.size(); i++)
		{
			cout << s3[i] << " ";
		}
	}
	void Test_string2()
	{
		string s1("hello world");
		string::iterator it1 = s1.begin();
		while (it1 != s1.end())
		{
			cout << *it1 << " ";
			it1++;
		}
		cout << endl;
		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;

		const string s2("xxxxxx");
		string::const_iterator it2 = s2.begin();
		while (it2 != s2.end())
		{
			cout << *it2 << " ";
			it2++;
		}
	}
	void Test_string3()
	{
		string s1("hello world");
		s1.push_back('1');
		s1.push_back('2');
		s1.push_back('3');
		s1.push_back('4');
		cout << s1.c_str() << endl;

		s1.append("bit");
		cout << s1.c_str() << endl;
	}
	void Test_string4()
	{
		string s1("hello world");
		s1 += 'x';
		s1 += "yyyyy";
		cout << s1.c_str() << endl;
	}
}