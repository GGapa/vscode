/*
#include <iostream>
using namespace std;

int main()
{
	int n, k, i, ky=0, bk=0, nuk = 0,nub=0;
	cin >> n >> k;
	double ak, ab;
	for (i = 1; i <= n; i++)
	{
		if (i % k == 0)
		{
			nuk++;
			ky = ky + i;
		}
		else
		{
			nub++;
			bk = bk + i;
		}
	}
	ak = double(ky) / double(nuk);
	ab = double(bk) / double(nub);
	printf("%.1f %.1f",ak,ab);
}
*/