/*
#include <iostream>
using namespace std;
#define maxn 10000001
int a[maxn] = { 0 };
bool cheak(int x)
{
	while (x != 0)
	{
		int temp = x % 10;
		if (temp == 7)return false;
		x /= 10;
	}
	return true;
}
int ls, ans[maxn];
void init()
{
	for (int i = 1; i <= maxn; i++)
	{
		if (a[i])continue;
		if (!cheak(i))
		{
			for (int j = i; j <= maxn; j += i)
			{
				a[j] = 1;
			}
			continue;
		}
		ans[ls] = i;
		ls = i;
	}
}
int main()
{
	init();
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (a[n])
			cout << -1 << endl;
		else 
			cout << ans[n] << "\n";
	}
	return 0;
}
*/