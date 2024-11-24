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
int a[300005];
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
	int n, k = 0, result = INT_MIN;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> node[i].left >> node[i].right;
	sort(node, node + n, cmp);
	for (int i = 0; i < n; i++)
	{
		bool cheak = true;
		for (int j = i - 1; j >= 0; j--)
		{
			if (rule(i, j) == false)
			{
				cheak = false;
				break;
			}
		}
		if (cheak == false)continue;
		else k++;
		for (int j = i + 1; j < n; j++)
		{
			if (rule(i, j) == false)
			{
				cheak = false;
				break;
			}
		}
		if (cheak == true)
		{
			result = max(result, node[i].right - node[i].left);
		}
	}
	cout << k * result << endl;
	return 0;
}
*/