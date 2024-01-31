/*
#include <iostream>
#include <cmath>
using namespace std;

int a[1024][1024];

void he(int x,int y,int z)
{
	if (x == 2)
	{
		a[y][z] = 0;
		return;
	}
	for (int i = y; i < y + x / 2; i++)
		for (int j = z; j < z + x / 2; j++)
			a[i][j] = 0;
	he(x / 2, y + x / 2, z);
	he(x / 2, y, z + x / 2);
	he(x / 2, y + x / 2, z + x / 2);
}

int main()
{
	int n;
	cin >> n;
	n = pow(2, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = 1;
	he(n, 0, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}
*/
