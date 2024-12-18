/*
#include <iostream>
using namespace std;

long long c, k, ans = 0;


void digui(long long x, long long y)
{
	if (x == 0 || y == 0)
		return;
	if (x == y)
	{
		ans += x * 4;
		return;
	}
	if (x > y) swap(x, y);
	ans += x * 4 * (y / x);
	digui(x, y %= x);
}


int main()
{
	cin >> c >> k;
	digui(c, k);
	cout << ans << endl;
}
*/