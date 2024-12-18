/*
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

struct peo
{
	string name;
	string job;
	int gongxian;
	int dengji;
	int shunxu;
};
peo people[120];
bool paixu(peo a, peo b)
{
	if (a.gongxian == b.gongxian)
	{
		return a.shunxu < b.shunxu;
	}
	else
		return a.gongxian > b.gongxian;
}
int zweiRank(string value)
{//HuFa,ZhangLao,TangZhu,JingYing,BangZhong
	if (value == "HuFa") return 0;
	else if (value == "ZhangLao")return 1;
	else if (value == "TangZhu")return 2;
	else if (value == "JingYing")return 3;
	else return 4;
}
bool paixu1(peo a, peo b)
{
	if (a.job == b.job)
	{
		if (a.dengji == b.dengji)
		{
			return a.shunxu < b.shunxu;
		}
		else
			return a.dengji > b.dengji;
	}

	return zweiRank(a.job) < zweiRank(b.job);
}
void zhiwei(int a)
{
	for (int i = 3; i < a; i++)
	{
		if (i <= 4)
		{
			people[i].job = "HuFa";
		}
		else if (i <= 8)
		{
			people[i].job = "ZhangLao";
		}
		else if (i <= 15)
		{
			people[i].job = "TangZhu";
		}
		else if (i <= 40)
		{
			people[i].job = "JingYing";
		}
		else
		{
			people[i].job = "BangZhong";
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> people[i].name >> people[i].job >> people[i].gongxian >> people[i].dengji;
		people[i].shunxu = i;
	}
	sort(people + 3, people + n, paixu);
	zhiwei(n);
	sort(people + 3, people + n, paixu1);
	for (int i = 0; i < n; i++)
	{
		cout << people[i].name << " " << people[i].job << " " << people[i].dengji << endl;
	}
	return 0;
}
*/