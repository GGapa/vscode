/*
#include <iostream>
using namespace std;
int  ans[10], m, n;
long long num[1000005][10] = { 0 };
void print()
{
	for (int i = 1; i <= n * m; i++)
	{
		int temp = i;
		while (temp != 0)
		{
			int wie = temp % 10;
			temp /= 10;
			num[i][wie]++;
		}
	}
}
int main()
{
	cin >> n >> m;
	print();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int temp = i * j;
			for (int q = 0; q < 10; q++)
			{
				ans[q] += num[temp][q];
			}
		}
	}
	for (int q = 0; q < 10; q++)
	{
		cout << ans[q] << endl;
	}
	return 0;
}
*/