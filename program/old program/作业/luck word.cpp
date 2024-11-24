/*
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	char a[101];
	int max=-1,num=0,small = 101;
	bool bj = true;
	cin >> a;
	for (int i = 97; i <= 123; i++)
	{
		num = 0;
		for (int j = 0; j < 100; j++)
		{
			if (a[j] == '\0')break;
			if (a[j] == i) num++;
		}
		if (num < small&&num!=0)
		{
			small = num;
		}
		if (num > max)
		{
			max = num;
		}

	}
	int ls = max - small;
	for (int i = 2; i <= sqrt(ls); i++)
	{
		if (ls == 2) break;
		if (ls % i == 0)
		{
			bj = false;
			break;
		}
	}
	if (ls == 0||ls==1) bj = false;
	if (bj)cout << "Lucky Word" << endl << ls << endl;
	else cout << "No Answer" << endl << 0 << endl;
}
*/