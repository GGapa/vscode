/*
#include <iostream>
#include <algorithm>
using namespace std;
int  a[5000000],k;
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
	if (k <= j)
		paixu(x, j);
	else if (k >= i)
		paixu(i, y);
	else
	{
		cout << a[k];
		exit(0);
	}
}
inline int read() 
{
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9') {
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
int main()
{
	int n;
	n = read();
	k = read();
	for (register int i = 0; i < n; ++i)a[i] = read();
	paixu(0, n - 1);
	cout << a[k] << endl;
	return 0;
}
*/