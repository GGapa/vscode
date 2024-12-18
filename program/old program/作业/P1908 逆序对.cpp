/*
#include <iostream>
using namespace std;
#define maxn 500015
long long n, a[maxn], b[maxn];
long long ans=0;
void cmp(int l, int r)
{
	if (l == r)return;
	long long temp = (l + r) / 2,x=l,y=temp+1,z=l;
	cmp(l, temp);
	cmp(temp + 1, r);
	while (x <= temp && y <= r)
	{
		if (a[x] <= a[y])
			b[z++] = a[x++];
		else
		{
			b[z++] = a[y++];
			ans += temp - x + 1;
		}
	}
	while (x <= temp)
	{
		b[z++] = a[x++];
	}
	while (y <= r)
	{
		b[z++] = a[y++];
	}
	for (int i = l; i <= r; i++)
		a[i] = b[i];
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	cmp(1, n);
	cout << ans << endl;
	return 0;
}
*/