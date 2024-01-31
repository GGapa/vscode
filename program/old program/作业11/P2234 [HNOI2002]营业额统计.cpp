/*
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
#define maxn 32768
multiset<long long >a;
long long ans = 0, num1 = -1, num2 = -1;
bool bj = true;
int main()
{
	int n;
	cin >> n;
	
	while (n--)
	{
		num1 = num2 = -1;
		int x;
		cin >> x;
		auto it1 = a.insert(x);
		auto it2 = it1;
		if (a.size() == 1)
		{
			ans += (x);
			bj = false;
		}
		else
		{
			bj = false;
			if (it1 != a.begin())
			{
				it1--;
				num1 = abs(x - *it1);
			}
			if (it2 != a.end())
			{
				if (++it2 != a.end())
				{
					num2 = abs(x - *it2);
				}
			}
			if (num1 == -1)
				ans += num2;
			else if (num2 == -1)
				ans += num1;
			else
				ans += min(num1, num2);

		}
	}
	cout << ans << endl;
	return 0;
}
*/