/*
#include <iostream>
#include <algorithm>
using namespace std;
int a[502];
int t[502];
int main()
{
	int n, r,num=1,ans=0;
	cin >> n >> r;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		t[num] += a[i];
		ans += t[num];
		num++;
		if (num >= r)
		{
			num = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
*/