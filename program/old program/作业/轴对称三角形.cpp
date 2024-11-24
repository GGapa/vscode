/*
#include <iostream>
using namespace std;

int main()
{
	int j, n, q, i,p,b,c;
	cin >> n;
	p = 1;
	char a;
	cin >> a;
	if(a=='x')
	{
		for (i = n; i > 0; i--)
		{
			for (j = 1; j <= i - 1; j++)
			{
				cout << " ";

			}
			for (j = 1; j <= p; j++)
			{
				cout << "*";
			}
			cout << endl;
			p = p + 2;
		}
		p = n + 2;
		for (i = n; i >= 1; i--)
		{
	for (j = 1; j <= n - i; j++)
			{
				cout << " ";

			}
			for (j = 1; j <= 2 * i - 1; j++)
			{
				cout << "*";
			}
			cout << endl;
			p = p - 2;
		}
	}
	if (a == 'y')
	{
		b = n - 1;
		c = 2 * n - 2;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= b; j++) cout << " ";
			for (j = 1; j <= (i * 2 - 1); j++) cout << "*";
			for (j = 1; j <= c; j++)cout << " ";
			for (j = 1; j <= (i * 2 - 1); j++) cout << "*";
			cout << endl;
			b -= 1;
			c -= 2;
		}
	}
}
*/