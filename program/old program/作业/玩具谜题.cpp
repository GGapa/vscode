/*
#include <iostream>
#include <cstring>
using namespace std;

struct people
{
	string job;
	int fangwie;
};
struct miti
{
	int fangxiang;
	int farward;
};

people toy[100000];
miti miaoshu[100000];
int main()
{
	int n, m,a=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> toy[i].fangwie >> toy[i].job;
	for (int i = 0; i < m; i++)
		cin >> miaoshu[i].fangxiang >> miaoshu[i].farward;
	for (int i = 0; i < m; i++)
	{
		if (miaoshu[i].fangxiang == 0)//Õ˘◊Û ˝
		{
			if (toy[a].fangwie == 0)//Õ˘»¶ƒ⁄
			{
				a -= miaoshu[i].farward;
				if (a < 0) a += n;
			}
			else if (toy[a].fangwie == 1)//Õ˘»¶Õ‚
			{
				a += miaoshu[i].farward;
				if (a >= n) a -= n;
			}
		}
		else if (miaoshu[i].fangxiang == 1)//Õ˘”“ ˝
		{
			if (toy[a].fangwie == 0)//Õ˘»¶ƒ⁄
			{
				a += miaoshu[i].farward;
				if (a >= n) a -= n;
			}
			else if (toy[a].fangwie == 1)//Õ˘»¶Õ‚
			{
				a -= miaoshu[i].farward;
				if (a < 0) a += n;
			}
		}
	}
	cout << toy[a].job << endl;
}
*/