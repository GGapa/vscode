/*
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n, i, j, a, num = 1,c=0,d=0;
	int b[200][200];
	bool bj = false;//false 0	true 1
	cin >> n;
	while (num <= n * n)
	{
		cin >> a;
		for (i = 0; i < a; i++)
		{
			if (bj)
				cout << 1;
			else
				cout << 0;
			num++;
			d++;
			if (d == n)
			{
				d = 0;
				cout << endl;
			}
		}
		if (bj)
			bj = false;
		else
			bj = true;
	}
	return 0;
}
*/