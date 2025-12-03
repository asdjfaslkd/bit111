#include <iostream>
using namespace std;

#include <stack>
#include <deque>
#include <algorithm>

#include "Stack.h"

void test_stack1()
{
    // bit::stack<int, list<int>> st;
    // bit::stack<int, vector<int>> st;
    bit::stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

// void test_op1()
// {
//     srand(time(0));
//     const int N = 1000000;

//     deque<int> dq;
//     vector<int> v;

//     for (int i = 0; i < N; ++i)
//     {
//         auto e = rand() + i;
//         v.push_back(e);
//         dq.push_back(e);
//     }

//     int begin1 = clock();
//     sort(v.begin(), v.end());
//     int end1 = clock();

//     int begin2 = clock();
//     sort(dq.begin(), dq.end());
//     int end2 = clock();

//     printf("vector:%d\n", end1 - begin1);
//     printf("deque:%d\n", end2 - begin2);
// }

// void test_op2()
// {
//     srand(time(0));
//     const int N = 1000000;

//     deque<int> dq1;
//     deque<int> dq2;

//     for (int i = 0; i < N; ++i)
//     {
//         auto e = rand() + i;
//         dq1.push_back(e);
//         dq2.push_back(e);
//     }

//     int begin1 = clock();
//     sort(dq1.begin(), dq1.end());
//     int end1 = clock();

//     int begin2 = clock();
//     // vector
//     vector<int> v(dq2.begin(), dq2.end());
//     sort(v.begin(), v.end());
//     dq2.assign(v.begin(), v.end());
//     int end2 = clock();

//     printf("deque sort:%d\n", end1 - begin1);
//     printf("deque copy vector sort, copy back deque:%d\n", end2 - begin2);
// }

// int main()
// {
//     // test_stack1();
//     test_op2();

//     return 0;
// }