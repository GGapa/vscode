/*
#include <iostream>
#include <string>
using namespace std;

int a[1000001], n, x;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cin >> x;
	bool bj = true;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == x)
		{
			bj = false;
			cout << i << endl;
			break;
		}
	}
	if (bj)
	{
		cout << -1 << endl;
	}
	return 0;
}
*/