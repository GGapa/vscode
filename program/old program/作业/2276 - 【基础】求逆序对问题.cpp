/*
#include <iostream>
using namespace std;
#define maxn 200000
long long a[maxn];
int main()
{
	long long n,ans=0,m;
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[i] > a[j] * 2)ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
*/