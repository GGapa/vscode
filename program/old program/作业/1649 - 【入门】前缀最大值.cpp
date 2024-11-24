/*
#include <iostream>
#include <limits.h>
using namespace std;
#define maxn 100005
long long n, x,a[maxn],ans=0,add=INT_MIN;
int main()
{
	cin >> n >> x;
	a[1] = x;
	for (int i = 2; i <= n; i++)
		a[i] = (379 * a[i - 1] + 131) % 997;
	for (int i = 1; i <= n; i++)
	{
		add = max(add, a[i]);
		ans += add;
	}
	cout << ans << endl;
	return 0;
}
*/