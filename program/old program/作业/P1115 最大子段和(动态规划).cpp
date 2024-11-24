/*
#include <iostream>
using namespace std;
long long a[1200000], ans = -9999999, n, anm = 0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		anm += a[i];
		ans = max(ans, anm);
		if (anm < 0)
		{
			anm = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
*/