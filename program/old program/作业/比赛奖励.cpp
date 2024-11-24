/*
#include <iostream>
using namespace std;

int main()
{
	long long n, ans = 0,sum=0;
	bool get1200 = true;
	cin >> n;
	int a[1005];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		get1200 = (a[i] == 0 ? false : get1200);
		if (a[i] <= 10 && a[i] != 0)ans += 200 + (11 - a[i]), sum++;
		else if (a[i] == 0);
		else sum = 0;
		if (sum == 6)sum = 0, ans += 1000;
	}
	if (get1200)ans += 1200;
	cout << ans << endl;
	return 0;
}
*/