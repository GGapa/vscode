/*
#include <iostream>
using namespace std;

int main()
{
	int n, a[10000], ans = 0;
	bool bj = true;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	while (bj)
	{
		bj = false;
		for (int i = 0; i < n - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				bj = true;
				ans++;
			}
		}
	}
	cout << ans<<endl;
	return 0;
}
*/