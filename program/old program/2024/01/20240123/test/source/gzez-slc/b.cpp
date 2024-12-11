#include <bits/stdc++.h>
using namespace std;

using graph = vector<vector<int>>;

const int maxn = 805;

void readTree(int n, vector<vector<int>> &U)
{
	U.resize(n);
	for (int i = 1; i < n; ++i) {
		int x;
		scanf("%d", &x);
		U[x - 1].push_back(i);
	}
}

void dfsA(int x, const graph &T, vector<int> &F)
{
	F[x] = 1;
	for (int y : T[x]) {
		dfsA(y, T, F);
		F[x] += F[y];
	}

	if (T[x].size() > 1)
		F[x] = 1;
}

bool dfsB(int x1, int x2, const graph &T1, const graph &T2)
{
	if (T[x1].size() > 1 && T[x2].size() == 1)
		return dfsB(x1, T[x2][0], T1, T2);
	if (T[x1].size() == 1 && T[x2].size() > 1)
		return dfsB(T[x1][0], x2, T1, T2);

	if (T[x1].size() != T[x2].size())
		return false;

	int s = T[x1].size();
	for (int i = 0; i < s; ++i) {
		if (!dfsB(T[x1][i], T[x2][i], T1, T2))
			return false;
	}
	return true;
}

vector<int> Fk[maxn];

int main()
{
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	int N = max(n1, n2);
	graph T1, T2;
	readTree(n1, T1);
	readTree(n2, T2);
	bool fz = !dfsB(0, 0, T1, T2);
	int q;
	scanf("%d", &q);

	vector<int> F1(n1), F2(n2), Fx(N + 1);
	dfsA(0, T1, F1);
	dfsA(0, T2, F2);
	for (int i = 0; i < q; ++i) {
		int t, x;
		scanf("%d %d", &t, &x);
		Fx[x] = (t == 1);
		int V = N + 1;
		Fk[0].clear();
		Fk[0].resize(V, 0);
		Fk[0][0] = 1;
		for (int i = 1; i < :
		if (fz) {
			puts("0");
			continue;
		}
