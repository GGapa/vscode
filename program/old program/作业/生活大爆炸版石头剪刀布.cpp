/*
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int shuying[5][5] = { 0,1,2,2,1,
					  2,0,1,2,1,
					  1,2,0,1,2,
					  1,1,2,0,2,
					  2,2,1,1,0 };
int main()
{
	int n, na, nb, a[200], b[200], la = 0, lb = 0, fa = 0, fb = 0, num = 0;
	cin >> n >> na >> nb;
	for (int i = 0; i < na; i++)cin >> a[i];
	for (int i = 0; i < nb; i++)cin >> b[i];
	for (int i = 1; i <= n; i++)
	{
		if (la == na)la = 0;
		if (lb == nb)lb = 0;
		int value = shuying[a[la]][b[lb]];
		if (value == 2)fa++;
		else if (value == 1) fb++;
		la++; lb++;
	}
	printf("%d %d", fa, fb);
	return 0;
}
*/