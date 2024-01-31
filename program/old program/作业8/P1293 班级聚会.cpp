/*
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

struct a
{
	int num;
	int km;
	string name;
};
bool paixu(a x, a y)
{
	return x.km > y.km;
}


int main()
{
	a city[160];
	long ls = -1,mmin=9999999999,money=0;
	string mcity;
	do
	{
		ls++;
		cin >> city[ls].num >> city[ls].km >> city[ls].name;
	} while (city[ls].name != "Moscow" && city[ls].km != 0);
	sort(city, city + ls, paixu);
	for (int i = 0; i <= ls; i++)
	{
		for (int j = 0; j <= ls; j++)
		{
			money += city[j].num * abs(city[i].km - city[j].km);
		}
		if (money <= mmin)
		{
			mmin = money;
			mcity = city[i].name;
		}
		money = 0;
	}
	cout << mcity << " " << mmin << endl;
	return 0;
}
*/