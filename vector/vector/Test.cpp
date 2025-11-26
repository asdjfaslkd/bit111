#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<vector>

void Test_vector1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	auto pos = find(v.begin(), v.end(), 3);
	if (pos != v.end())
	{
		v.insert(pos, 30);
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	
	// Í·²å
	v.insert(v.begin(), 0);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.insert(v.begin() + 2, 0);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	string s("abcd");
	v.insert(v.begin(), s.begin(), s.end());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	Test_vector1();
	return 0;
}