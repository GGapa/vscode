/*
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct n_
{
	string name;
	int ppp;
};

n_ n[9];
bool paixu(int x, int y)
{
	return x > y;
}
bool paixu2(n_ x, n_ y)
{
	return x.ppp > y.ppp;
}
int main()
{
	int a = 3, b = 5,x[9]={1,9,2,8,7,5,6,4,3};
	for (int i = 0; i < 9; i++)
	{
		n[i].ppp = x[i];
	}
	cout << max(a, b) << endl;
	cout << min(a, b) << endl;
	sort(x, x + 9);
	for (int i = 0; i < 9; i++)
	{
		cout << x[i];
	}
	cout << endl;
	sort(x, x + 9, paixu);
	for (int i = 0; i < 9; i++)
	{
		cout << x[i];
	}
	sort(n, n + 9, paixu2);
	cout << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << n[i].name << " " << n[i].ppp;
	}
	return 0;
}
*/