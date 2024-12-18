/*
#include <iostream>
using namespace std;
#define maxn 1025
int map[maxn][maxn], fx[4] = { -1,-1,1,1 }, fy[4] = { -1,1,-1,1 }, n, k, qx, qy;
void digui(int lx, int ly, int gx, int gy, int len)
{
	if (len == 1)return;
	if (gx - lx <= len / 2 - 1 && gy - ly <= len / 2 - 1)//第二象限
	{
		cout << lx + len / 2 << " " << ly + len / 2 << " " << 1 << endl;
		digui(lx, ly, gx, gy, len / 2);//2
		digui(lx, ly + len / 2, lx + len / 2 - 1, ly + len / 2, len / 2);//1
		digui(lx + len / 2, ly, lx + len / 2, ly + len / 2 - 1, len / 2);//3
		digui(lx + len / 2, ly + len / 2, lx + len / 2, ly + len / 2, len / 2);//4
	}
	if (gx - lx <= len / 2 - 1 && gy - ly >= len / 2)
	{
		cout << lx + len / 2 << " " << ly + len / 2 - 1 << " " << 2 << endl;
		digui(lx, ly + len / 2, gx, gy, len / 2);//1
		digui(lx, ly, lx + len / 2 - 1, ly + len / 2 - 1, len / 2);//2
		digui(lx + len / 2, ly, lx + len / 2, ly + len / 2 - 1, len / 2);//3
		digui(lx + len / 2, ly + len / 2, lx + len / 2, ly + len / 2, len / 2);//4
	}

	if (gx - lx >= len / 2 && gy - ly <= len / 2 - 1)//3
	{
		cout << lx + len / 2 - 1 << " " << ly + len / 2 << " " << 3 << endl;
		digui(lx, ly + len / 2, lx + len / 2 - 1, ly + len / 2, len / 2);//1
		digui(lx, ly, lx + len / 2 - 1, ly + len / 2 - 1, len / 2);
		digui(lx + len / 2, ly, gx, gy, len / 2);
		digui(lx + len / 2, ly + len / 2, lx + len / 2, ly + len / 2, len / 2);
	}
	if (gx - lx >= len / 2 && gy - ly >= len / 2)
	{
		cout << lx + len / 2 - 1 << " " << ly + len / 2 - 1 << " " << 4 << endl;
		digui(lx, ly + len / 2, lx + len / 2 - 1, ly + len / 2, len / 2);
		digui(lx, ly, lx + len / 2 - 1, ly + len / 2 - 1, len / 2);
		digui(lx + len / 2, ly, lx + len / 2, ly + len / 2 - 1, len / 2);
		digui(lx + len / 2, ly + len / 2, gx, gy, len / 2);
	}
}
int main()
{
	cin >> k;
	n = 1 << k;
	cin >> qx >> qy;
	digui(1, 1, qx, qy, n);
	return 0;
}
*/