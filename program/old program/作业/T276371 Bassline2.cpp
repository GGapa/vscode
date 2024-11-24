/*
#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits.h>
using namespace std;
struct st
{
	int left, right;
};
st node[300005];
int a[300005] = { -1 };
bool cmp(st x, st y)
{
	return x.left + x.right < y.left + y.right;
}
bool rule(int i, int j)
{
	if ((node[i].left > node[j].left && node[i].right > node[j].right)
		|| ((node[i].left < node[j].right && node[i].right < node[j].left) ||
			(node[i].left > node[j].right && node[i].right > node[i].left)))
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int n, k = 0, result = INT_MIN, ma = INT_MIN, mw, mr = 1;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> node[i].left >> node[i].right;
	sort(node, node + n, cmp);
	for (int i = 0; i < n; i++)a[i] = 0;
	for (int i = 0; i < n; i++)
	{
		mr = max(node[i].right, mr);
		for (int j = node[i].left; j <= node[i].right; j++)
		{
			a[j]++;
			ma = max(ma, a[j]);
		}
	}
	bool first = true;
	int ans = INT_MIN, left = 0, right = 0, sum;
	for (int i = 0; i < mr; i++)
	{
		if (a[i + 1] == ma)
		{
			k = a[i];
			left = right = i;
			while (a[left - 1] == k)
			{
				left--;
				if (left < 1)
				{
					left = 1;
					break;
				}
			}
		}
		ans = max(ans, k * (right - left));
		if (a[i + 1] != ma && a[i] == ma)
		{
			k = a[i + 1];
			left = right = i + 1;
			while (a[right + 1] == k)
			{
				right++;
				if (a[right] == -1)
				{
					right--;
					break;
				}
			}
		}
		ans = max(ans, k * (right - left));
	}
	cout << ans << endl;
	return 0;
}
*/