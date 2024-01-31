/*
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
#define maxn (1<<15)+1
int a[maxn], n,bj[maxn];
stack <string> ans;
bool cheak()
{
	bool temp = true;
	for (int i = 0; i < n; i++)
		if (bj[i] = 0)
			temp = false;
	return temp;
}
void dfs(int x)
{
	if (cheak())
	{
		while (!ans.empty())
		{
			cout << ans.top() << endl;
			ans.pop();
		}
		exit(0);
	}
	if (x >= n||bj[x]==1)return;
	dfs(x + 1);
	bj[x] = 1;
	for (int i = 0; i < n; i++)
	{
		string temp;
		if (bj[i] == 1)temp += "X";
		else temp += "0";
		ans.push(temp);
	}
	dfs(x + 1);
	bj[x] = 0;
	ans.pop();
}
int main()
{
	cin >> n;
	ans.push("000");
	dfs(0);
	return 0;
}
*/