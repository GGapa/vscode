/*
#include <iostream>
using namespace std;
int c[1001] = { 0 };
int a[1001] = { 0 }, b[1001] = { 0 };


void jia()
{
	for (int i = 1000; i >=0; i--)
	{
		c[i] = a[i] + b[i];
	}
	for (int i = 1000; i >= 0; i--)
	{
		if (c[i] >= 10)
		{
			c[i - 1] += 1;
			c[i] -= 10;
		}
	}
	for (int i = 1000; i >= 0; i--)
	{
		b[i] = a[i];
		a[i] = c[i];
	}
}


int main()
{
	a[1000] = 1; b[1000] = 1;
	int s, e;
	cin >> s >> e;
	if (e - s < 2)
	{
		cout << 1 << endl;
		return 0;
	}
	for (int i = s; i < e-1; i++)
	{
		jia();
	}
	bool bj = false;
	for (int i = 0; i < 1001; i++)
	{
		if (a[i] != 0)bj = true;
		if (bj)
			cout << a[i];
	}
	cout << endl;
	return 0;
}
*/