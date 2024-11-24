/*
#include <iostream>
using namespace std;

int main()
{
	int n, x, k, num = 0, ans = 0, week = 0;
	bool br = false;
	cin >> n;

	int w = n / 52;


	for (int k = 1; k <= 100; k++)
	{
		int total = k + 2 * k + 3 * k + 4 * k + 5 * k + 6 * k;
		for (int x = 1; x <= 100; x++)
		{
			if ((x * 7 + total) == w)
			{
				cout << x << endl << k << endl;
				return 0;
			}
		}
	}
}
*/