/*
#include <iostream>
using namespace std;

int main()
{
	int i, j, q,n,ans=0,N;
	cin >> N;
	n = N * 10;
	for (i = 1; i <= n / 8;i++)
	{
		for (j = 1; j <= n / 2; j++)
		{
			for (q = 1; q <= n; q++)
			{
				if (i * 8 + j * 2 + q == n&&i+j+q>30)
				{
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
*/