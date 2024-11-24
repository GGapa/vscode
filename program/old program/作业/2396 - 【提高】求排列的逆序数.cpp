/*
#include <iostream>
using namespace std;
long long a[100000];
int main()
{
	long long ans = 0, n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				ans++;
		}
	}
	cout << ans << endl;
}
*/