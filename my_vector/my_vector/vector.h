#include <assert.h>

namespace bit
{
    template <class T>
    class vector
    {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;

        const_iterator begin() const
        {
            return _start;
        }
        const_iterator end() const
        {
            return _finish;
        }
        iterator begin()
        {
            return _start;
        }
        iterator end()
        {
            return _finish;
        }
        vector() {}
        ~vector()
        {
            delete[] _start;
            _start = _finish = _endofstorage = nullptr;
        }
        size_t size() const
        {
            return _finish - _start;
        }
        size_t capacity() const
        {
            return _endofstorage - _start;
        }
        T& operator[](size_t pos)
        {
            assert(pos < size());
            return _start[pos];
        }
        const T& operator[](size_t pos) const
        {
            assert(pos < size());
            return _start[pos];
        }
        void reserve(size_t n)
        {
            if (n > capacity())
            {
                T* tmp = new T[n];
                size_t old_size = size();
                memcpy(tmp, _start, sizeof(T) * size());
                delete[] _start;
                _start = tmp;
                _finish = tmp + old_size;
                _endofstorage = tmp + n;
            }
        }
        // T()是匿名对象
        void resize(size_t n, const T& val = T())
        {
        }
        void push_back(const T& val)
        {
            // if (_finish == _endofstorage)
            // {
            //     size_t old_size = size();
            //     size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
            //     T *tmp = new T[newcapacity];
            //     memcpy(tmp, _start, size() * sizeof(T));
            //     delete[] _start;
            //     _start = tmp;
            //     _finish = tmp + old_size;
            //     _endofstorage = tmp + newcapacity;
            // }
            if (_finish == _start)
            {
                reserve(capacity() == 0 ? 4 : capacity() * 2);
            }
            *_finish = val;
            ++_finish;
        }
        void pop_back()
        {
            assert(!empty());
            --_finish;
        }
        bool empty()
        {
            return _finish == _start;
        }
        void insert(iterator pos, const T& val)
        {
            assert(pos >= _start);
            assert(pos <= _finish);

            if (_finish == _start)
            {
                size_t len = pos - _start;
                reserve(capacity() == 0 ? 4 : capacity() * 2);
                pos = _start + len;
            }
            iterator it = _finish - 1;
            while (it >= pos)
            {
                *(it + 1) = *it;
                it++;
            }
            *pos = val;
            ++_finish;
        }
        void erase(iterator pos)
        {
            assert(pos >= _start);
            assert(pos <= _finish);
            iterator it = pos + 1;
            while (it < _finish)
            {
                *(it - 1) = *it;
                it++;
            }
            --_finish;
        }

    private:
        iterator _start = nullptr;
        iterator _finish = nullptr;
        iterator _endofstorage = nullptr;
    };
    template <class T>
    void Print_vector(const vector<T>& v)
    {
        for (size_t i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        typename vector<T>::const_iterator it = v.begin();
        // auto it = v.begin();
        while (it != v.end())
        {
            cout << *it << " ";
            it++;
        }
        cout << endl;
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    void Test_vector1()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        v.push_back(4);

        for (size_t i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }
    void Test_vector2()
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);

        vector<int>::iterator it = v.begin();
        while (it != v.end())
        {
            cout << *it << " ";
            it++;
        }
        cout << endl;
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    void Test_vector3()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        Print_vector(v1);

        vector<double> v2;
        v2.push_back(1.1);
        v2.push_back(2.2);
        v2.push_back(3.3);
        v2.push_back(4.4);
        Print_vector(v2);
    }
}