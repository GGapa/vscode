/*
#include <iostream>
using namespace std;

int main()
{
	long long n, m, ls = 0, ansc = 0, ansz = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			long long ls = min(i, j);
			ansz += ls;
			ansc += i * j - ls;
		}
	}
	cout << ansz << " " << ansc << endl;
}
*/