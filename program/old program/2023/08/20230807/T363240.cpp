// T363240 洗牌
// https://www.luogu.com.cn/problem/T363240?contestId=123906
#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], out[maxn], b[maxn];
int n, m;

struct stru_tree
{
	int left, right;
	long long number, lazy;
};

stru_tree tree[maxn * 4 + 2];

inline void make_tree(int it, int left, int right) // Without problem
{
	tree[it].left = left;
	tree[it].right = right;
	if (left == right)
	{
		tree[it].number = a[left];
		return;
	}
	int middle = (left + right) >> 1;
	make_tree(it * 2, left, middle);
	make_tree(it * 2 + 1, middle + 1, right);
	tree[it].number = tree[it * 2].number + tree[it * 2 + 1].number;
}

inline void update(int it)
{
	if (tree[it].lazy != 0)
	{
		tree[it * 2].number += tree[it].lazy * (tree[it * 2].right - tree[it * 2].left + 1);
		tree[it * 2 + 1].number += tree[it].lazy * (tree[it * 2 + 1].right - tree[it * 2 + 1].left + 1);
		tree[it * 2 + 1].lazy += tree[it].lazy;
		tree[it * 2].lazy += tree[it].lazy;
		tree[it].lazy = 0;
	}
}

inline void change(int it, int left, int right, long long add)
{
	if (left <= tree[it].left && right >= tree[it].right)
	{
		tree[it].number += add * (long long)(tree[it].right - tree[it].left + 1);
		tree[it].lazy += add;
		return;
	}
	update(it);
	int middle = (tree[it].left + tree[it].right) >> 1;
	if (left <= middle)
		change(it * 2, left, right, add);
	if (right > middle)
		change(it * 2 + 1, left, right, add);
	tree[it].number = tree[it * 2 + 1].number + tree[it * 2].number;
}

inline long long reply(int it, int left, int right) // Without problem
{
	if (left <= tree[it].left && right >= tree[it].right)
	{
		return tree[it].number;
	}
	update(it);
	int middle = (tree[it].left + tree[it].right) >> 1;
	long long ans = 0;
	if (left <= middle)
		ans += reply(it * 2, left, right);
	if (right > middle)
		ans += reply(it * 2 + 1, left, right);
	return ans;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> b[i], a[i] = i;
	make_tree(1, 1, n);
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		int posl, posr;
		for (int i = 1; i <= n; i++)
		{
			if (b[i] == l)
				posl = i;
			if (b[i] == r)
			{
				posr = i;
				break;
			}
		}
		int backs = n - posr;
		change(1, posl, posr, backs);
		int fronts = posr - posl + 1;
		change(1, posr + 1, n, -fronts);
	}
	for (int i = 1; i <= n; i++)
	{
		int tmp = reply(1, i, i);
		out[tmp] = b[i];
	}
	for (int i = 5; i >= 1; i--)
	{
		cout << out[i] << " ";
	}
	return 0;
}