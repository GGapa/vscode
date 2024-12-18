/*
#include <iostream>
using namespace std;

int b[1000][7];
int main()
{
	int i, j, q, a[7], c[7], n, m, num;
	cin >> n;
	for (i = 0; i < 7; i++)
	{
		cin >> a[i];
		c[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		for (q = 0; q < 7; q++)
		{
			cin >> b[i][q];
		}
	}
	for (i = 0; i <= n; i++)
	{
		num = 0;
		for (q = 0; q < 7; q++)
		{
			for (j = 0; j < 7; j++)
			{
				if (b[i][q] == a[j])
				{
					num++;
				}
			}

		}
		if (num != 0)c[7 - num]++;
	}A
	for (i = 0; i < 7; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
	return 0;
}
*/