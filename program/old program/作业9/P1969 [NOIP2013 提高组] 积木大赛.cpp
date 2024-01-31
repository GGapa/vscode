/*
#include <iostream>
using namespace std;

int n, a[100000];
long ans = 0;


void digui(int l, int r)
{
	int mv,m=100001;
	bool bj = true;
	if (l == r || r==0 || l>=n)return;
	for (int i = l; i < r; i++)
	{
		if (a[i] != 0)
		{
			bj = false;
			break;
		}
	}
	if(bj)return;
	for (int i = l; i < r; i++)
	{
		if (a[i] < m)
		{
			mv = i; m = a[i];
		}
	}
	if (m != 0)
	{
		for (int i = l; i < r; i++)
		{
			if(a[i]!=0)a[i] -= m;
		}
		ans += m;

	}
	digui(l, mv);
	digui(mv + 1, r);
}



int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	digui(0,n);
	cout << ans << endl;
}
*/