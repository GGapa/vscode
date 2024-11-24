/*
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k, b[101], f[101] = { 0 }, used = 0, ans = 0;
struct food
{
	int num, vaule;
}a[201];
bool cmp(food x, food y)
{
	return x.num > y.num;
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++)cin >> b[i];
	for (int i = 0; i < n; i++)cin >> a[i].num >> a[i].vaule;
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++)
	{
		if (f[a[i].vaule] < b[a[i].vaule]&&used < m)
		{
			f[a[i].vaule]++;
			used++;
			ans += a[i].num;
		}
	}
	cout << ans << endl;
	return 0;
}
*/