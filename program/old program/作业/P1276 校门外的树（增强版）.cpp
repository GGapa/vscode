/*
#include <iostream>
using namespace std;
#define maxn 10001
int a[maxn] = { 0 };
long long ans1 = 0, ans2 = 0;
int main()
{
	int l, n;
	cin >> l >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 0)
		{
			for (int j = y; j <= z; j++)
			{
				if (a[j] == 1)ans2++, ans1--;
				a[j] = 2;
			}
		}
		if (x == 1)
		{
			for (int j = y; j <= z; j++)
			{
				if (a[j] == 2)ans1++, a[j] = 1;
			}
		}
	}
	cout << ans1 << endl << ans2 << endl;
	return 0;
}
*/