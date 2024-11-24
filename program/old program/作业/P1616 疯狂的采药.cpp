/*
#include <iostream>
using namespace std;
#define maxm 10000005
long long bag[maxm] = { 0 };
struct n
{
	long long time, money;
};
n a[maxm];
int t, m;
void debug()
{
	for (int i = 1; i <= t; i++)
		cout << bag[i] << " ";
	cout << endl;
}
int main()
{
	cin >> t >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].time >> a[i].money;
	}
	for (int j = 1; j <= t; j++)
	{
		for (int i = 1; i <= m; i++)
		{
			if (j - a[i].time >= 0)
				bag[j] = max(bag[j ], bag[j - a[i].time] + a[i].money);
			else
				bag[j] = bag[j ];
			//debug();
		}
	}
	cout << bag[t] << endl;
	return 0;
}
*/