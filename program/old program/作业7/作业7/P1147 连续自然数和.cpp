/*
#include <iostream>
using namespace std;
long long a[20000001],ans = -9999999, n, anm = 0,start=0;
int main()
{
	for (int i = 0; i < 2000000;i++)
	{
		a[i] = i;
	}
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		anm += i;
		if (anm >n)
		{
			anm = 0;
			i = start;
			start++;
			continue;
		}
		if (anm == n && start!=i)
		{
			cout << start << " " << i << endl;
		}
	}
	return 0;
}
*/