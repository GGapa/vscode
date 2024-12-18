/*
#include <iostream>
using namespace std;

int a[100000],n;

void paixu(int x, int y)
{
	int i = x, j = y, top, ls;
	top = a[(x + y) / 2];
	do
	{
		while (a[i] < top)i++;
		while (a[j] > top)j--;
		if (i <= j)
		{
			ls = a[i]; a[i] = a[j]; a[j] = ls;
			i++; j--;
		}
	} while (i <= j);
	if (x < j)paixu(x, j);
	if (i < y)paixu(i, y);
}
int main()
{
	int i;
	cin >> n;
	for (i = 0; i < n; i++)cin >> a[i];
	paixu(0,n-1);
	for (i = 0; i < n; i++)cout << a[i] << " ";
	return 0;
}
*/