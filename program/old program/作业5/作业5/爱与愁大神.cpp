/*
#include <iostream>
using namespace std;

int main()
{
	int n, i, small=10000,m,a[3000],b=0,num=0,ls;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> a[i];
	ls = b;
	for (i = 0; i < m + 1; i++)
	{
		if (b >= n - 1|| ls + i>=n-1) break;
		num += a[ls + i];
		if (i == m) 
		{
			b++;
			i = 0;
			ls = b;
			if (num < small) small = num;
			num = 0;
		}
	}
	if (num < small) small = num;
	cout << small;
}
*/