/*
#include <iostream>
using namespace std;
#define maxn 4005
long long ss, mm, n;
long long bag[maxn][maxn], s[maxn], m[maxn], k[maxn];
void debug()
{
	for (int i = 1; i <= mm; i++)
	{
		printf("%4d", i);
	}
	for (int i = 1; i <= ss; i++)
	{
		printf("%4d", i);
		for (int j = 1; j <= mm; j++)
			printf("%4d", bag[i][j]);
		cout << endl;
	}
}
int main()
{
	cin >> ss >> mm >> n;
	for (int i = 1; i <= n; i++)
		cin >> s[i] >> m[i] >> k[i];
	for (int q = 1; q <= n; q++)
	{
		for (int i = ss; i >= s[q]; i--)
		{
			for (int j = mm; j >= m[q]; j--)
			{
				if (i - s[q] >= 0 && j - m[q] >= 0)
				{
					bag[i][j] = max(bag[i][j], bag[i - s[q]][j - m[q]] + k[q]);
				}
			}
		}
	}
	cout << bag[ss][mm] << endl;
	return 0;
}
*/