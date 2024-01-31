/*
#include <iostream>
using namespace std;

int main()
{
	int i, j, n;
	cin >> n;
	for (i = 1; i <= n / 2 + 1; i++)
	{
		for (j = n/2+i; j >= n-n/2+1; j--)
		{
			cout << " ";
		}
		for (j = 1; j <= n; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (i = 1; i <= n / 2 + 1; i++)
	{
		if (i == 1)
		{
			continue;
		}
		for (j = n / 2 - i; j >= 0; j--)
		{
			cout << " ";
		}
		for (j = 1; j <= n; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}
*/