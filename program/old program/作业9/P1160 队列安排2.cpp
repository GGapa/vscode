/*
#include <iostream>
#include <list>
#include <string>
using namespace std;

list<int> a;
list<int>::iterator it[100000];

int main()
{
	int n;
	cin >> n;
	a.push_front(1);
	it[1] = a.begin();
	for (int i = 2; i <= n; i++)
	{
		int k, p;
		cin >> k >> p;
		if (p)
		{
			auto ls = next(it[k]);
			it[i] = a.insert(ls, i);
		}
		else
		{
			it[i] = a.insert(it[k], i);
		}
	}
	int m;
	cin >> m;
	bool e[100000] = { false };
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		if (!e[x])
		{
			a.erase(it[x]);
		}
		e[x] = true;
	}
	bool f = true;
	for (int x : a)
	{
		if (!f)
		{
			cout << " ";
		}
		f = false;
		cout << x;
	}
	cout << endl;
	return 0;
}
*/