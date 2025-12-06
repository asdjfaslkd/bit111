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
		size_t size() const
		{
			return _size;
		}
		size_t capacity() const
		{
			return _capacity;
		}
		string(const char* str = "")
			: _size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}
		const char* c_str() const
		{
			return _str;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);

			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}
		string& operator+=(const char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		// void push_back(char ch)
		// {
		// 	// À©ÈÝ
		// 	if (_size == _capacity)
		// 	{
		// 		size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
		// 		char *tmp = new char[newcapacity + 1];
		// 		strcpy(tmp, _str);
		// 		delete[] _str;
		// 		_str = tmp;
		// 		_capacity = newcapacity;
		// 	}
		// 	_str[_size] = ch;
		// 	_size++;
		// 	_str[_size] = '\0';
		// }
		void resever(size_t n)
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
		// void resize(size_t n)
		// {
		// 	if (n <= _size)
		// 	{
		// 		_str[_size] = '\0';
		// 		_size = n;
		// 	}
		// 	else
		// 	{
		// 		resever(n);
		// 		for (size_t i = _size; i < n; i++)
		// 		{
		// 			_str[i] = '\0';
		// 		}
		// 		_size = n;
		// 	}
		// }
		void resize(size_t n, char ch = '\0')
		{
			if (n <= _size)
			{
				_str[_size] = '\0';
				_size = n;
			}
			else
			{
				resever(n);
				for (size_t i = _size; i < n; i++)
				{
					_str[i] = ch;
				}
				_size = n;
			}
		}
		void push_back(char ch)
		{
			if (_capacity == _size)
			{
				resever(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (len + _size > _capacity)
			{
				resever(len + _size);
			}
			strcpy(_str + _size, str);
			_size += len;
		}
		void insert(size_t pos, char ch)
		{
			assert(pos < _size);
			if (_size == _capacity)
			{
				resever(_capacity == 0 ? 4 : _capacity * 2);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			_size++;
		}
		void insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				resever(_size + len);
			}
			size_t end = _size + len;
			while (end > pos + len - 1)
			{
				_str[end] = _str[end - len];
				--end;
			}
			strncpy(_str + pos, str, len);
			_size += len;
		}
		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos || len > _size - pos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		size_t find(char ch, size_t pos = 0) const
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* sub, size_t pos = 0) const
		{
			assert(pos < _size);
			const char* p = strstr(_str + pos, sub);
			if (p)
			{
				return p - _str;
			}
			else
			{
				return npos;
			}
		}
		string substr(size_t pos = 0, size_t len = npos)
		{
			string sub;
			// if (len == npos || len >= _size-pos)
			if (len >= _size - pos)
			{
				for (size_t i = pos; i < _size; i++)
				{
					sub += _str[i];
				}
			}
			else
			{
				for (size_t i = pos; i < pos + len; i++)
				{
					sub += _str[i];
				}
			}

			return sub;
		}
		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	public:
		const static int npos;
	};
	const int string::npos = -1;

	void swap(string& x, string& y)
	{
		x.swap(y);
	}

	bool operator==(const string& s1, const string& s2)
	{
		int ret = strcmp(s1.c_str(), s2.c_str());
		return ret == 0;
	}

	bool operator<(const string& s1, const string& s2)
	{
		int ret = strcmp(s1.c_str(), s2.c_str());
		return ret < 0;
	}

	bool operator<=(const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}

	bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}

	bool operator>=(const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}

	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}

		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();

		char ch;
		// in >> ch;
		ch = in.get();
		char buff[128];
		size_t i = 0;
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			// [0,126]
			if (i == 127)
			{
				buff[127] = '\0';
				s += buff;
				i = 0;
			}

			ch = in.get();
		}

		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}

		return in;
	}
	// istream& operator>>(istream& in, string& s)
	//{
	//	s.clear();
	//	char ch;
	//	//in >> ch;
	//	ch = in.get();
	//	s.reserve(128);
	//	while (ch != '\n' && ch != ' ')
	//	{
	//		s += ch;
	//		ch = in.get();
	//	}

	//	return in;
	//}

	istream& getline(istream& in, string& s)
	{
		s.clear();

		char ch;
		// in >> ch;
		ch = in.get();
		char buff[128];
		size_t i = 0;
		while (ch != '\n')
		{
			buff[i++] = ch;
			// [0,126]
			if (i == 127)
			{
				buff[127] = '\0';
				s += buff;
				i = 0;
			}

			ch = in.get();
		}

		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}

		return in;
	}
	void Test_string1()
	{
		string s1("hello world");
		string s2;
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		string s3("hello bit");
		for (size_t i = 0; i < s3.size(); i++)
		{
			cout << s3[i] << " ";
		}
		cout << endl;

		string::iterator it3 = s3.begin();
		while (it3 != s3.end())
		{
			cout << *it3 << " ";
			++it3;
		}
		cout << endl;
		for (auto ch : s3)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	void Test_string2()
	{
		string s1("hello world");
		string s2;
		s1.push_back('!');
		s2.push_back('h');
		s2.push_back('e');
		s2.push_back('l');
		s2.push_back('l');
		s2.push_back('o');
		s2.push_back('!');
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		s2.append("hello bit");
		cout << s2.c_str() << endl;
	}
	void Test_string3()
	{
		string s1("hello world");
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;
		s1.resize(3);
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;
	}
	void Test_string4()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;
		s1.insert(5, 'x');
		cout << s1.c_str() << endl;

		s1.insert(5, "yyy");
		cout << s1.c_str() << endl;
	}
	void Test_string5()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		s1.erase(5, 2);
		cout << s1.c_str() << endl;

		s1.erase(5);
		cout << s1.c_str() << endl;
	}
	void test_string6()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		string s2(s1);
		cout << s2.c_str() << endl;

		s1[0] = 'x';

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		string s3("xxxxx");
		s1 = s3;

		cout << s1.c_str() << endl;
		cout << s3.c_str() << endl;
	}

	void test_string7()
	{
		string s1("hello world");
		cout << s1.c_str() << endl;

		s1.insert(6, "xxx");
		cout << s1.c_str() << endl;

		string s2("xxxxxxx");

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		swap(s1, s2);
		s1.swap(s2);
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
	}

	void test_string8()
	{
		string url1("https://legacy.cplusplus.com/reference/string/string/substr/");
		string url2("http://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&rsv_idx=1&tn=65081411_1_oem_dg&wd=%E5%90%8E%E7%BC%80%20%E8%8B%B1%E6%96%87&fenlei=256&rsv_pq=0xc17a6c03003ede72&rsv_t=7f6eqaxivkivsW9Zwc41K2mIRleeNXjmiMjOgoAC0UgwLzPyVm%2FtSOeppDv%2F&rqlang=en&rsv_dl=ib&rsv_enter=1&rsv_sug3=4&rsv_sug1=3&rsv_sug7=100&rsv_sug2=0&rsv_btype=i&inputT=1588&rsv_sug4=6786");

		string protocol, domain, uri;
		size_t i1 = url1.find(':');
		if (i1 != string::npos)
		{
			protocol = url1.substr(0, i1 - 0);
			cout << protocol.c_str() << endl;
		}

		// strchar
		size_t i2 = url1.find('/', i1 + 3);
		if (i2 != string::npos)
		{
			domain = url1.substr(i1 + 3, i2 - (i1 + 3));
			cout << domain.c_str() << endl;

			uri = url1.substr(i2 + 1);
			cout << uri.c_str() << endl;
		}

		// strstr
		size_t i3 = url1.find("baidu");
		cout << i3 << endl;
	}

	void test_string9()
	{
		string s1("hello world");
		string s2("hello world");

		cout << (s1 == s2) << endl;

		cout << ("hello world" == s2) << endl;
		cout << (s1 == "hello world") << endl;

		cout << s1 << endl;
		cout << s2 << endl;

		cin >> s1 >> s2;

		cout << s1 << endl;
		cout << s2 << endl;

		getline(cin, s1);
		cout << s1 << endl;
	}

	void test_string10()
	{
		string s1;

		cin >> s1;
		cout << s1.capacity() << endl;
	}

	void test_string11()
	{
		string s1("hello world");
		string s2(s1);

		cout << s1 << endl;
		cout << s2 << endl;

		string s3("xxxxxxxxxxxxxxxxxxxxxxxxx");
		s1 = s3;
	}
}