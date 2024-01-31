/*
#include <iostream>
using namespace std;
int h[20000];
void paixu(int x, int y)
{
	int i = x, j = y, top, ls;
	top = h[(x + y) / 2];
	do
	{
		while (h[i] < top)i++;
		while (h[j] > top)j--;
		if (i <= j)
		{
			ls = h[i]; h[i] = h[j]; h[j] = ls;
			i++; j--;
		}
	} while (i <= j);
	if (x < j)paixu(x, j);
	if (i < y)paixu(i, y);
}
int main()
{
	int b,n;
	cin >> n>>b;
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	paixu(0, n);
	int all=0,num=0;
	for (int i = n; i >0 ; i--)
	{
		all += h[i];
		num++;
		if (all >= b) 
		{
			cout << num << endl;
			break;
		}
	}
	return 0;
}
*/