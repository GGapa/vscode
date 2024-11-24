/*
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	double xnsc, ynsc,a[1000];
	int n;
	cin >> xnsc >> ynsc;
	double ls = 1000 / ynsc;
	a[0] = xnsc * ls;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		double x, y;
		cin >> x >> y;
		double c = 1000/y;
		a[i+1] = x * c;
	}
	sort(a, a + n);
	printf("%.2f", a[0]);
}
*/