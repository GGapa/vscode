/*
#include <iostream>
#include <cmath>
using namespace std;

bool zhishu(int x)
{
	int t = sqrt(x);
	for (int i = 2; i <= t; i++)
	{
		if (x % i == 0)return false;
	}
	return true;
}




int main()
{
	int n;
	cin >> n;
	for (int i = 2; i < n/2; i++)
	{
		if (i % 2==0&&i!=2)continue;
		if (zhishu(i))
		{
			int t = n % i;
			if ( t == 0)
			{
				int v = n / i;
				if (v % 2 == 0&&v!=2)continue;
				if (zhishu(v))
				{
					cout << v << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}

*/