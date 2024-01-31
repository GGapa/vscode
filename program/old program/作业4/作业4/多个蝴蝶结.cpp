/*
#include <iostream>
using namespace std;

int main()
{
	int i, j, n, p, a;
	cin >> n;
	p = 1;
	a = n - 1;
	for (i = 1; i <= n / 2 + 1; i++)
	{
		for (j = 1; j <= p; j++) cout << "*";
		for (j = 1; j <= a; j++)cout << " ";
		for (j = 1; j <= p; j++) cout << "*";
		p++;
		a -= 2;
		cout << endl;
	}
	p = n / 2;
	a = 2;
	for (i = n / 2 + 1; i <= n - 1; i++)
	{
		for (j = 1; j <= p; j++) cout << "*";
		for (j = 1; j <= a; j++)cout << " ";
		for (j = 1; j <= p; j++) cout << "*";
		p--;
		a += 2;
		cout << endl;
	}
	return 0;
}
*/