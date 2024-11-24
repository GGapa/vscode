/*
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int map[1001][1001] = { 0 };
priority_queue<int, vector<int>, greater<int> > node[100001];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
		node[x].push(y);
		node[y].push(x);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << node[i].size() << " ";
		while (!node[i].empty())
		{
			cout << node[i].top() << " ";
			node[i].pop();
		}
		cout << endl;
	}
	return 0;
}
*/