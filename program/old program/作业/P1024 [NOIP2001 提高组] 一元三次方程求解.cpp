/*
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a, b, c, d, A, B, C, der, num = 0;
	cin >> a >> b >> c >> d;
	for (double i = -100; i <= 100; i += 0.001)
	{
		double l = i, r = i + 0.001;
		if ((a * l * l * l + b * l * l + c * l + d) * (a * r * r * r + b * r * r + c * r + d) < 0)
		{
			printf("%.2f ", l);
			num++;
		}
		if (num == 3)
			break;
	}
	return 0;
}

*/