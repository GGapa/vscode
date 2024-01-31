/*
#include <iostream>
using namespace std;
int bag[10001] = { 0 }, p[10001], t[10001], m, n;
int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++)cin >> p[i] >> t[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = t[i]; j <= m; j++)
		{
			bag[j] = max(bag[j], p[i] + bag[j - t[i]]);
		}
	}
	cout << bag[m] << endl;
	return 0;
}
*/