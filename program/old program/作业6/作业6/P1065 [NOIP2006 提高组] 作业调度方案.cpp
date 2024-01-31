/*
#include <iostream>
using namespace std;

int sx[20000], jq[20][20000] = { 0 };

struct a
{
	int num;
	int gongxu[20];
	int time[20];
	int gnow = 0;
	int wc = 1;
	int end = 0;
};


int main()
{
	a gongjian[20];
	int m, n,max=-1;
	cin >> m >> n;
	for (int i = 0; i < m * n; i++)
		cin >> sx[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> gongjian[i].gongxu[j];
		}
		gongjian[i].num = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> gongjian[i].time[j];
	}
	for (int i = 0; i < m * n; i++)
	{
		int INDEX = sx[i] - 1;
		bool b = false, bj = true;
		int t = 0, ls, start = 0;
		ls = (gongjian[INDEX].time[gongjian[INDEX].gnow]);
		int ls1 = gongjian[INDEX].gongxu[gongjian[INDEX].gnow] - 1;
		for (int q = 0; q < 20000; q++)
		{
			bj = true;
			for (int x = q; x < q + ls; x++)
			{
				if (jq[ls1][x] != 0)bj = false;
			}

			if (bj)
			{
				int j;
				b = false;
				for (j = q; j < q + ls; j++)
				{
					if (gongjian[INDEX].end <= q)
					{
						jq[ls1][j] = gongjian[INDEX].num;
						b = true;
					}
				}
				if (b)
				{
					gongjian[INDEX].end = j;
					gongjian[INDEX].wc++; gongjian[INDEX].gnow++;
					if (gongjian[INDEX].end > max)max = gongjian[INDEX].end;
					break;
				}
			}
		}
	}
	cout << max << endl;
	return 0;
}
*/