/*
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[100], n,ans=0;
	bool bj;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n;i++)
	{
		bj = false;
		for (int j = 0; j < i; j++)
		{
			if (a[i] == a[j])
			{
				bj = true;
				continue;
			}
		}
		if (bj)a[i] = 0;
		else ans++;
	}
	sort(a, a + n);
	cout << ans<<endl;
	for (int i = 0; i < n; i++)
	{
		if(a[i]!=0)cout << a[i] << " ";
	}
	cout << endl;
	return 0;

}
*/