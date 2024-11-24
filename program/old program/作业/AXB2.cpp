/*

#include <iostream>
#include <cstring>
using namespace std;


int c[10000] = { 0 }, ls1 = 0;
int a[4000] = { 0 }, b[4000] = { 0 }, B[4000] = { 0 };



bool cheng(long long A, long long B)
{

	int i, lsA = 0, ls = 0, j;
	bool bj = false;
	for (i = 0; i < 4000; i++)
	{
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}
	while (A > 0)
	{
		a[lsA] = A % 10;
		A = A / 10;
		lsA++;
	}
	ls = 0;
	while (B > 0)
	{
		b[ls] = B % 10;
		B = B / 10;
		ls++;
	}

	for (i = 0; i <= lsA; i++)
	{
		for (j = 0; j <= ls; j++)
		{
			c[i + j] += a[i] * b[j];
		}

		ls1 = c[i] / 10;
		c[i] -= ls1 * 10;
		if (c[i] > 1)
			return false;
		c[i + 1] += ls1;
	}
	for (i = 0; i < 3999; i++)
	{
		ls1 = c[i] / 10;
		c[i] -= ls1 * 10;
		if (c[i] > 1)
			return false;
		c[i + 1] += ls1;
	}

	for (i = 3999; i >= 0; i--)
	{
		if (c[i] != 0)bj = true;
		if (bj)cout << c[i];
	}
	cout << endl;
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
	while ((A % 10) == 0)
	{
		A = A / 10;
	}

	int m = A % 10, step = 1, len = 1;
	if (m == 1)step = 1;
	if (m == 2)step = 5;
	if (m == 3)step = 7;
	if (m == 4)step = 5;
	if (m == 5)step = 2;
	if (m == 6)step = 5;
	if (m == 7)step = 3;
	if (m == 8)step = 5;
	if (m == 9)step = 9;

	if ((m % 2) == 0) len = 2;

	for (int i = step; i < INT64_MAX; i += 10)
	{
		if (cheng(i, A))
		{
			cout << i << endl;
			break;
		}
	}


}
*/