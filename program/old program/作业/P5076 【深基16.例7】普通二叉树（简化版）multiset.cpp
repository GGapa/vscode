/*
#include <iostream>
#include <set>
using namespace std;
#define maxn 10001
multiset<int> tree;
int start = -1, xmax = -2147483647, xmin = 2147483647, ranknum = 1, findnum = 1, num = 1;
int main()
{
	//tree.insert(-2147483647);
	//tree.insert(2147483647);
	int n, x, y;
	cin >> n;
	while (n--)
	{
		cin >> x >> y;
		if (x == 1)
		{
			bool bj = true;
			num = 0;
			auto it = tree.begin();
			it;
			for (auto it = tree.begin(); it != tree.end(); it++)
			{
				num++;
				if (*it == y)
				{
					bj = false;
					cout << num << endl;
					break;
				}
				if (*it > y)
				{
					bj = false;
					cout << num << endl;
					break;
				}
			}
			if (bj)
			{
				cout << num + 1 << endl;
			}
		}
		else if (x == 2)
		{
			num = 1;
			auto it = tree.begin();
			while (num != y)
			{
				num++;
				it++;
			}
			cout << *it << endl;
		}
		else if (x == 3)
		{
			auto it = tree.lower_bound(y);
			if (it != tree.begin())
				cout << *--it << endl;
			else
				cout << -2147483647 << endl;
		}
		else if (x == 4)
		{
			auto it = tree.upper_bound(y);
			if (it != tree.end())
				cout << *it << endl;
			else
				cout << 2147483647 << endl;
		}
		else if (x == 5)
		{
			tree.insert(y);
		}
	}
	return 0;
}
*/