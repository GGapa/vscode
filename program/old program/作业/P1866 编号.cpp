/*
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int x, maxnumber[52], n;
	long long ans = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> maxnumber[i];
	}
	sort(maxnumber + 1, maxnumber + n + 1);
	for (int i = 1; i <= n; i++)
	{
		ans *= (maxnumber[i]-i+1);
		ans %= 1000000007;
	}
	cout << ans << endl;
	return 0;
}
*/