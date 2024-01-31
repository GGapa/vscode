/*
#include <iostream>
#include <cmath>
using namespace std;

int c[10000] = { 0 };
long long a[10000] = { 0 };

void chu(string A, int b)
{
	int i, ls=0, j;
	bool bj = false;
	for (i = 0; i < 4000; i++)
	{
		a[i] = -1;
		c[i] = -1;
	}
	for (i = 0; i < A.length(); i++)
		a[i] = A[i] - '0';
	if (a[0] == 0)
	{
		c[0] = 0;
		return;
	}
	for (i = 0; i <= A.length(); i++)
	{
		if (a[i]==-1||i> A.length()-1)break;
		if (a[i] < b)
		{
			a[i + 1] += a[i] * 10; a[i] = 0;
			c[ls++] = 0;
			continue;
		}
		a[i + 1] += a[i] % b * 10;
		c[ls++] =a[i]/b;
		a[i] = 0;
	}
}

int main()
{
	string A;
	int B;
	bool bj = false;
	cin >> A >> B;
	chu(A, B);
	for (int i = 0; i < 5000; i++)
	{
		if (c[i] == -1)break;
		if (c[i] != 0)bj = true;
		if(bj)cout << c[i];
	}
	cout << endl;
	return 0;
}
*/