/*
#include <iostream>
using namespace std;
int bag[20000005], a[25];
int main()
{
	int n, b;
	cin >> n >> b;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = b; j >= 1; j--)
		{
			bag[j] = (j - a[i] >= 0) ? max(bag[j], bag[j - a[i]] + a[i]) : bag[j];
		}
	}
	cout << abs(bag[b] - b) << endl;
	return 0;
}

*/