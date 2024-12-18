/*
#include <iostream>
#include <cstring>
using namespace std;

char a[1000][1000], al[1000][1000], b[1000][1000];


int main()
{
	int n;
	string c = "";
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> b[i][j];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int q = 0; q < n; q++)
			{
				if (a[j][q] == 'O')
				{
					c += b[j][q];
				}
				al[j][q] = a[n - q - 1][j];
			}
		}
		for (int j = 0; j < n; j++)
		{
			for (int q = 0; q < n; q++)
			{
				a[j][q] = al[j][q];
			}
		}
	}
	cout << c << endl;
	return 0;
}
*/