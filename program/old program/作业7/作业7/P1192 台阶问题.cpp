/*
#include <iostream>
using namespace std;
#define mod 100003;


int a[101000] = { 0 };

int main()
{
	a[0] = 1;
	int n, k, ls = 0;
	cin >> n >> k;
	for (int i = 1; i < n+1; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if(i>=j)
			{
				a[i] += (a[i-j]);
			}
		}
		a[i] %= mod;
	}
	cout << a[n] << endl;
	return 0;
}
*/