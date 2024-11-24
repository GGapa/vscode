/*
#include <iostream>
using namespace std;

int main()
{
	int a[3005], i, b, m, n, num = 0, small = 3000000, ans = 0;
	cin >> m >> n;
	for (i = 0; i < m; i++)
		cin >> a[i];
	for (i = 0; i < m; i++)
	{
		ans += a[i];
 		if (i >= n-1)
		{
			if(i>n-1) ans -= a[i - n];
			if (ans < small)small = ans;
		}
	}
	if (ans < small)small = ans;
	cout << small << endl;
	return 0;
}
&*/