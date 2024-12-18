/*
#include<iostream>
using namespace std;

int main()
{
	int a[3];
	char b[3];
	int i,bj=1,big;
	for (i = 0; i < 3; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < 3; i++)
	{
		cin >> b[i];
	}
	while (bj == 1)
	{
		bj = 0;
		for (i = 0; i < 3-1; i++)
		{
			if (a[i] > a[i + 1])
			{
				big = a[i];
				a[i] = a[i + 1];
				a[i + 1] = big;
				bj = 1;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		if (b[i] == 'A')cout << a[0]<<" ";
		if (b[i] == 'B')cout << a[1]<<" ";
		if (b[i] == 'C')cout << a[2]<<" ";
	}
	cout << endl;
}
*/