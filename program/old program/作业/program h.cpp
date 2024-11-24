/*
#include <iostream>
#include <cmath>
using namespace std;
int chu;
void p(int x, int y)
{
	int ls = max(x, y);
	for (int i = sqrt(ls) + 1; i > 2; i--)
	{
		if (x % ls == 0 && y % ls == 0)
		{
			chu = i;
			return;
		}
	}
	chu = 1;
	return;
}

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int z1, z2, z, m;
	if (b == d)
	{
		chu = 0;
		m = d;
		z = a + c;
		if (z == 0)
		{
			cout << 0 << endl;
		}
		int bj = 0;
		if (z % m == 0)
		{
			cout << z / m << endl;
			bj = 1;
		}
		else cout << z << " " << m << endl;


		bj = 0;
		z = a - c;
		if (z == 0)
		{
			cout << 0 << endl;
		}
		else if (z % m == 0)
		{
			cout << z / m << endl;
			bj = 1;
		}
		else cout << z << " " << m << endl;

		bj = 0;
		m = b * d;
		z = a * c;
		if (z == 0)
		{
			cout << 0 << endl;
		}
		else if (z % m == 0)
		{
			cout << z / m << endl;
			bj = 1;
		}
		else cout << z << " " << m << endl;

		bj = 0;
		m = b * c;
		z = a * d;
		if (z == 0)
		{
			cout << 0 << endl;
		}
		else if (z % m == 0)
		{
			cout << z / m << endl;
			bj = 1;
		}
		else cout << z << " " << m << endl;
	}
	else if (b != d)
	{
		int bj;
		m = b * d;
		z = a * d + c * d;
		if (z == 0)
		{
			cout << 0 << endl;
			bj = 1;
		}
		else if (z % m == 0)
		{
			cout << z / m << endl;
			bj = 1;
		}
		if (!bj)
		{
			do
			{
				p(z, m);
				if (chu != 1)
				{
					z /= chu; m /= chu;
				}
			} while (chu != 1);
			cout << z << " " << m << endl;
		}





		bj = 0;
		m = b * d; z = a * d - c * d;
		if (z == 0)
		{
			cout << 0 << endl;
			bj = 1;
		}
		else if (z % m == 0)
		{
			cout << z / m << endl;
			bj = 1;
		}
		if (!bj)
		{
			do
			{
				p(z, m);
				if (chu != 1)
				{
					z /= chu; m /= chu;
				}
			} while (chu != 1);
			cout << z << " " << m << endl;
		}





		bj = 0;
		m = b * d;
		z = a * c;
		if (z == 0)
		{
			cout << 0 << endl;
			bj = 1;
		}
		else if (z % m == 0)
		{
			cout << z / m << endl;
			bj = 1;
		}
		if (!bj)
		{
			do
			{
				p(z, m);
				if (chu != 1)
				{
					z /= chu; m /= chu;
				}
			} while (chu != 1);
			cout << z << " " << m << endl;
		}








		bj = 0;
		m = b * c;
		z = a * d;
		if (z == 0)
		{
			cout << 0 << endl;
			bj = 1;
		}
		else if (z % m == 0)
		{
			cout << z / m << endl;
			bj = 1;
		}
		if (!bj)
		{
			do
			{
				p(z, m);
				if (chu != 1)
				{
					z /= chu; m /= chu;
				}
			} while (chu != 1);
			cout << z << " " << m << endl;
		}
	}
	return 0;
}
*/