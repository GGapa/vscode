/*
#include <iostream>
using namespace std;

int a[100000][3], t[100000][3];
int main()
{
	int i, j, ans = 0, n, m;
	cin >> m >> n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cin >> a[i][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		if (a[i][0] == 2 && a[i][1] == a[i][2])
		{
			ans++;
			continue;
		}
		if (a[i][1] > m || a[i][2] > m)
		{
			ans++;
			continue;
		}
		for (j = 0; j < i; j++)
		{
			if (a[i][0] != t[j][0] && ((a[i][1] == t[j][1] && a[i][2] == t[j][2])||
				(a[i][1] == t[j][2] && a[i][2] == t[j][1])))
			{
				ans++;
				break;
			}
			if (a[i][0] == 2 && a[i][0] == t[j][0] && a[i][1] == t[j][2] && a[i][2] == t[j][1])
			{
				ans++;
				break;
			}
		}
		for (j = 0; j < 3; j++)
		{
			t[i][j] = a[i][j];
		}

	}
	cout << ans << endl;
	return 0;
}
*/