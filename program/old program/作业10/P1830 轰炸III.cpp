/*
#include <iostream>
using namespace std;

int main()
{
	int n, m, x, y, x1, y1, x2, y2, a[101][101] = { 0 }, o, p, b[101][101] = { 0 };
	cin >> x >> m >> x >> y;
	for (int i = 0; i < x; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j <= x2; j++)
		{
			for (int q = y1; q <= y2; q++)
			{
				a[j][q] = i + 1;
				b[j][q]++;
			}
		}
	}
	for (int i = 0; i < y; i++)
	{
		cin >> o >> p;
		if (b[o][p] > 0)
		{
			cout << "Y " << b[o][p] << " " << a[o][p] << endl;
		}
		else
		{
			cout << "N" << endl;
		}
	}
}
*/