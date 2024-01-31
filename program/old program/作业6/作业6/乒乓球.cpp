/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
char a[62600];

int main()
{
	int x=0, y=0;
	for (int i = 0; i < 62600; i++)
	{
		cin >> a[i];
		if (a[i] == 'E')break;
	}
	for (int i = 0; i < 62600; i++)
	{
		if ((x - y >= 2 || y - x >= 2) && (x >= 11 || y >= 11))
		{
			printf("%d:%d\r\n", x, y);
			x = 0; y = 0;
		}
		if (a[i] == 'E')
		{
			printf("%d:%d\r\n", x, y);
			break;
		}
		if (a[i] == 'W')x++;
		if (a[i] == 'L')y++;
	}
	cout << endl;
	x = 0; y = 0;
	for (int i = 0; i < 626000; i++)
	{
		if ((x - y >= 2 || y - x >= 2) && (x >= 21 || y >= 21))
		{
			printf("%d:%d\r\n", x, y);
			x = 0; y = 0;
		}
		if (a[i] == 'E')
		{
			printf("%d:%d\r\n", x, y);
			x = 0; y = 0;
			break;
		}
		if (a[i] == 'W')x++;
		if (a[i] == 'L')y++;
	}
	return 0;
}
*/