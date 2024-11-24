/*
#include <iostream>
#include <vector>
using namespace std;
#define mod 80112002
#define maxn 5005
vector<long long>food[maxn];
vector<long long>eat[maxn];
long long ans[maxn], f[maxn] = { 0 }, l[maxn] = { 0 }, start = 0, last = 0, bj[maxn] = { 0 }, total = 0;
int bfs(int x)
{
	if (l[x] == 0) return 1;
	if (bj[x] != 0) return bj[x];
	int cnt = 0;
	for (int i = 0; i < food[x].size(); i++)
	{
		cnt = (cnt+bfs(food[x][i]))%mod;
	}
	bj[x] = cnt;
	return cnt;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int in1, in2;
		cin >> in1 >> in2;
		f[in2]++;
		l[in1]++;
		//eat[in2].push_back(in1);
		food[in1].push_back(in2);
	}
	for (int i = 1; i <= n; i++)
	{
		if (f[i] == 0)
			total = (total + bfs(i)) % mod;
	}
	cout << total << endl;
	return 0;
}
*/