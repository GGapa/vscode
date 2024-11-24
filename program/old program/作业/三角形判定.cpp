/*
#include <iostream>
#include<cmath>
using namespace std;

int main()
{
	int a[3],i=0,biaoji = 0,big = -1;
	for (i = 0; i < 3; i++)
	{
		cin >> a[i];
	}
	i = 0;
	while (biaoji == 0)
	{
		biaoji = 1;
		for (i = 0; i < 2; i++)
		{
			if (a[i] > a[i + 1])
			{
				big = a[i + 1];
				a[i + 1] = a[i];
				a[i] = big;
				biaoji = 0;
			}
		}
	}
	if (a[0] + a[1] <= a[2]||a[0]<=0||a[1]<=0||a[2]<=0) {
		cout << "Not triangle" << endl;
		return 0;
	}
	if (pow(a[0], 2) + pow(a[1], 2) == pow(a[2], 2)) cout << "Right triangle" << endl;
	if (pow(a[0], 2) + pow(a[1], 2) > pow(a[2], 2)) cout << "Acute triangle" << endl;
	if (pow(a[0], 2) + pow(a[1], 2) < pow(a[2], 2)) cout << "Obtuse triangle" << endl;
	if (a[0] == a[1] || a[1]==a[2]
		|| a[0] ==a[2]) cout << "Isosceles triangle" << endl;
	if (a[0] == a[1] && a[1] == a[2]) cout << "Equilateral triangle" << endl;

}
*/