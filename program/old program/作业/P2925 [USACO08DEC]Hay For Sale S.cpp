/*
#include <iostream>
#include <cstring>
using namespace std;
long long c, h, a[50001] = { 0 }, v[500001] = { 0 };
int main()
{
	cin >> c >> h;
	for (int i = 1; i <= h; i++)cin >> a[i];
	for (int i = 1; i <= h; i++)
	{
		for (int j = c; j >= 1; j--)
			if (j - a[i] >= 0)v[j] = max(v[j], v[j - a[i]] + a[i]);
	}
	cout << v[c] << endl;
	return 0;
}
*/