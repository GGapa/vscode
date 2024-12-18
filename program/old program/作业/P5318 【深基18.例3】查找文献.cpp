/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define maxm 1000005
#define maxn 100005
struct node_
{
	int vaule = 0, son = 0;
};
vector <node_> node;

vector<int> nodeb[maxn];

int look[maxn];
int n = 0, m = 0;
queue<int> a;
void bfs()
{
	while (!a.empty())
	{
		if (look[a.front()] == 1)
		{
			a.pop();
			continue;
		}
		look[a.front()] = 1;
		cout << a.front() << " ";
		bool bj = false;
		for (int i = 0; i < nodeb[a.front()].size(); i++)
		{
			int t = node[nodeb[a.front()][i]].son;
			if (look[t] == 0)
			{
				a.push(t);
				bj = true;
			}
		}
		a.pop();
	}
}
void dfs(int x)
{
	look[x] = 1;
	cout << x << " ";
	for (int i = 0; i < nodeb[x].size(); i++)
	{
		if (look[node[nodeb[x][i]].son] == 0)
		{
			dfs(node[nodeb[x][i]].son);
		}
	}
}
bool paixu(node_ x, node_ y)
{
	if (x.vaule == y.vaule)
		return x.son < y.son;
	else
		return x.vaule < y.vaule;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		node_ ls1;
		cin >> ls1.vaule >> ls1.son;
		node.push_back(ls1);
	}
	sort(node.begin(), node.end(), paixu);

	for (int i = 0; i < node.size(); i++)
	{
		nodeb[node[i].vaule].push_back(i);
	}

	dfs(1);
	for (int i = 0; i < maxn; i++)
		look[i] = 0;
	cout << endl;
	a.push(node[0].vaule);
	bfs();
	return 0;
}
*/