/*
#include <iostream>
using namespace std;
#define maxn 1005
long long n, x, ans = 0, num = 0,bag[maxn];
struct peo
{
	int lose, win, use;
};
peo a[maxn];
int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].lose >> a[i].win >> a[i].use;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = x; j >= a[i].use; j--)
			bag[j] = max(bag[j] + a[i].lose, bag[j - a[i].use] + a[i].win);
		for (int j = a[i].use - 1; j >= 0; j--)
			bag[j] += a[i].lose;
	}
	cout << bag[x]*5 << endl;
	return 0;
}
*/