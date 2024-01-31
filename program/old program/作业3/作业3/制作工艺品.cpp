/*
#include <iostream>
using namespace std;

int main()
{
	int a[20][20][20], w, x, h, q, x1, y1, z1, i, j,q_,x2,y2,z2,num=0;
	cin >> w >> x >> h;
	for (i = 0; i < w; i++)
	{
		for (j = 0; j < x; j++)
		{
			for (q_ = 0; q_ < h; q_++)
			{
				a[i][j][q_] = 1;
			}
		}
	}
	cin >> q;
	for (int m = 1; m <= q; m++)
	{
		cin >> x1 >> y1 >> z1>>x2>>y2>>z2;
		x1--; y1--; z1--;
		for (i = x1; i < x2; i++)
		{
			for (j = y1; j < y2; j++)
			{
				for (q_ = z1; q_ < z2; q_++)
				{
					a[i][j][q_] = 0;
				}
			}
		}
	}
	for (i = 0; i < w; i++)
	{
		for (j = 0; j < x; j++)
		{
			for (q_ = 0; q_ < h; q_++)
			{
				if (a[i][j][q_] == 1)num++;
			}
		}
	}
	cout << num << endl;
	return 0;
}
*/