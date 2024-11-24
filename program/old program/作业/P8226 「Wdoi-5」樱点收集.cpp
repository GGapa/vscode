/*
#include <iostream>
using namespace std;
int a[300001], b[300001];

int read() {
	long long f = 1, k = 0;
	char c = getchar();
	while (c < '0' || c>'9') {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		k = k * 10 + c - '0';
		c = getchar();
	}
	return f * k;
}


int main()
{
	long long n, m, k, ans = 0, ma = 0, num = 0, bomb = -1;
	cin >> n >> m >> k;
	int ls1 = 0;
	for (int i = 0; i < m; i++)
	{
		b[read() - 1] = 1;
	}
	ls1 = 0;
	for (int i = 0; i < n; i++)
	{
		a[ls1++] = read();
	}
	while (bomb <= n)
	{
		if ((a[bomb] == 0 || a[bomb] % k == 0)&&bomb!=-1)
		{
			bomb++;
			continue;
		}
		num = 0;
		for (int i = 0; i < n; i++)
		{
			if (i == bomb || a[i] == 0)continue;
			num += a[i];
			if (num % k == 0)
			{
				if (b[i])
				{
					ans++;
				}
				num = 0;
			}
			else num %= k;
		}
		bomb++;
		if (ans > ma)
		{
			ma = ans;
		}
		ans = 0;
	}
	cout << ma << endl;
	return 0;
}
*/