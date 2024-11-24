/*
#include <iostream>
using namespace std;

int main()
{
	int i, j, n,a,b;
	cin >> n;
	a = n - 1;
	b = 2 * n - 2;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= a; j++) cout << " ";
		for (j = 1; j <= (i * 2 - 1); j++) cout << "*";
		for (j = 1; j <= b; j++) cout << " ";
		for (j = 1; j <= (i * 2 - 1); j++) cout << "*";
		for (j = 1; j <= b; j++) cout << " ";
		for (j = 1; j <= (i * 2 - 1); j++) cout << "*";
		for (j = 1; j <= b; j++) cout << " ";
		a -= 1;
		b -= 2;
		cout << endl;
	}
}
*/