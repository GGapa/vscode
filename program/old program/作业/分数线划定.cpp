/*
#include <iostream>
#include <cstdio>
using namespace std;

struct jx
{
	int haoma;
	int chengji;
};

int main()
{
	jx people[6000];
	int m, n;
	bool bj = true;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> people[i].haoma >> people[i].chengji;
	}
	while (bj)
	{
		bj = false;
		for (int i = 0; i < n - 1; i++)
		{
			if (people[i].chengji < people[i + 1].chengji||(people[i].chengji == people[i + 1].chengji && people[i].haoma> people[i+1].haoma))
			{
				int ls = people[i + 1].chengji;
				people[i + 1].chengji = people[i].chengji;
				people[i].chengji = ls;
				ls = people[i + 1].haoma;
				people[i + 1].haoma = people[i].haoma;
				people[i].haoma = ls;
				bj = true;
			}
		}
	}
	m *= 1.5;
	int xian = people[m-1].chengji;
	int i=0,num=0;
	while (people[i].chengji >= xian)
	{
		num++; i++;
	}
	printf("%d %d\r\n",xian,num);
	for (i = 0; i < num; i++)
	{
		printf("%d %d\r\n", people[i].haoma, people[i].chengji);
	}
	return 0;
}
*/