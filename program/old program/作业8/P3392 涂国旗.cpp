/*
#include<iostream>
using namespace std;

int main()
{
	char a[50][50];
	int b[50][3] = { 0 }, n, m, ans = 0, mans = 99999;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] != 'W')
				b[i][0]++;
			if (a[i][j] != 'B')
				b[i][1]++;
			if (a[i][j] != 'R')
				b[i][2]++;
		}
	}
	for (int i = 1; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			for (int q = 0; q < i; q++)ans += b[q][0];
			for (int q = i; q < j; q++)ans += b[q][1];
			for (int q = j; q < n; q++)ans += b[q][2];
			mans = min(ans, mans);
			ans = 0;
		}
	}
	cout << mans << endl;
}
*/