/*
#include <iostream>
#include <algorithm>
using namespace std;
#define mod 1000000007
#define maxn 100000
int main(){
	int n,a[maxn],gcd=1,temp[maxn];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < maxn; i++)
		temp[i] = i + 1;
	if (a[0] == a[n - 1])
	{
		gcd = a[0];
		cout << a[0] << " " << 1 << endl;
	}
	else
	{
		long long ans=1;
		for (int i = 1; i < n; i++)
		{
			ans *= temp[i];
			ans %= mod;
	}
		cout << 1 << " " << ans << endl;
	}
	return 0;
}
*/