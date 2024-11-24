/*
#include <iostream>
using namespace std;

int main()
{
	int a[1001], n,i,j,num=0,b[1001];
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0;i < n;i++)
	{
		num = 0;
		for (j = i; j >= 0; j--)
		{
			if (a[i] > a[j]) num++;
		}
		b[i] = num;
	}
	for (i = 0; i < n; i++)
	{
		if (i == n - 1) cout << b[i]<<endl;
		else cout << b[i] << " ";
	}
}
*/