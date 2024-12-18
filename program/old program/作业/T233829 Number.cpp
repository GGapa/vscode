/*
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int n, a[10];
	string a1, a2;
	for (int i = 0; i <= 9; i++)
		cin >> a[i];
	for (char i = '9'; i >= '0'; i--)
	{
		while (a[i - '0'] > 0)
		{
			i % 2 == 0 ? a1 += i : a2 += i;
			a[i - '0']--;
		}
	}
	cout << a1 << endl;
	cout << a2 << endl;
}
*/