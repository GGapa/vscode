/*P2841*/
/*
#include <iostream>
#include <cstring>
using namespace std;

int c[10000] = { 0 },ls1=0;
long long a[50] = { 0 }, B[40] = { 0 };

bool chu(int b)
{
	int i, ls = 0, j;
	bool bj = false;
	for (i = 0; i < 40; i++)
	{
		a[i] = 0;

	}
	for (i = 0; i < 10000; i++) c[i] = { -1 };
	ls1 = 0;
	for (i = 39; i >= 0; i--)
	{
		if (B[i] != -1)
		{
			a[ls++] = B[i];
			ls1++;
		}
	}
	ls = 0;
	for (i = 0; i < 40; i++)
	{
		if ((a[i] == -1 || i >= ls1) && bj == false)
		{
			c[ls++] = -2;//-2是小数点
			bj = true;
		}
		if (a[i] < b)
		{
			a[i + 1] += a[i] * 10; a[i] = 0;
			c[ls++] = 0;
			continue;
		}
		a[i + 1] += a[i] % b * 10;
		c[ls++] = a[i] / b;
		a[i] = 0;
		if (bj == true && c[ls] != 0&&c[ls]!=-2)return false;
	}
	return true;
}


int main()
{
	B[0] = 0;
	for (int i = 1; i < 40; i++)
	{
		B[i] = -1;
	}
	long long A;
	long long ls = 0;
	bool bj = false, bj1 = false;
	cin >> A;
	for (long long b = 1; b < 9999999; b++)
	{
		B[0]++;
		for (int i = 0; i < 39; i++)
		{
			if (B[i] > 1) {
				B[i] = 0;
				B[i + 1] == -1 ? B[i + 1] += 2 : B[i + 1]++;
			}
			if (B[i] == -1) break;
		}
		int bj3 = false;
		if (chu(A))
		{
			for (int i = 0; i < 40; i++)
			{
				if (c[i] == -1)break;
				if (c[i] != 0)bj3 = true;
				if (bj3)
				{
					if (c[i] == -2)
					{
						cout << " ";
						break;
					}
					cout << c[i];
				}
			}
			for (int i = ls1-1; i >=0; i--)
			{
				if (B[i] == -1)break;
				cout << B[i];
			}
			cout << endl;
			return 0;
		}
	}
	return 0;
}
*/