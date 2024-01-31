/*
#include <iostream>
using namespace std;
struct ac
{
	int beg, end;
};
ac a[101];
int n, bj[101], ti[25], ans = 0, num = 0;
void dfs(int x)
{
	if (x >= n)
		return;
	dfs(x + 1);
	bool br = false;
	for (int i = a[x].beg; i < a[x].end; i++)
	{
		if (ti[i] == 1)
		{
			br = true;
			break;
		}
	}
	if (br)
		return;
	bool s = true;
	num++;
	for (int i = a[x].beg; i < a[x].end; i++)
	{
		ti[i] = 1;
	}
	ans = max(ans, num);
	dfs(x + 1);
	for (int i = a[x].beg; i < a[x].end; i++)
	{
		ti[i] = 0;
	}
	num--;
	ans = max(ans, num);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].beg >> a[i].end;
	}
	dfs(0);
	cout << ans << endl;
}
*/