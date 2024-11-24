/*
#include <iostream>
#include <cmath>
using namespace std;
int n, i, q, j,a[100];
int zhishu(int a)
{
	if (a == 0 || a == 1)return false;
	for (i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0) return false;
	}
	return true;
}


int main()
{
	
	cin >> n;
	for (j = 0; j < n; j++)
	{
		cin >> a[j];
	}
	for (j = 0; j < n; j++)
	{
		if (zhishu(a[j]))cout << a[j] << " ";
			
	}
	cout << endl;
	return 0;
}
*/