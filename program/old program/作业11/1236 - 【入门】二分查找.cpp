/*
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
int a[100001], n, x;
void digui(int l, int r)
{
	if (l == r)
	{
		cout << -1 << endl;
		return;
	}
	int ls = (l + r) / 2;
	if (a[ls] == x)
	{
		cout << ls << endl;
		return;
	}
	if (a[ls] > x)
		digui(l, ls);
	if (a[ls] < x)
		digui(ls, r);

}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cin >> x;
	digui(1, n);
	return 0;
}
*/