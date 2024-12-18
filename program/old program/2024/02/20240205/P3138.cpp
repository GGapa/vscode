#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>
#define LB(x) ((x) & (-(x)))
using namespace std;

int n, ny;
map<int, vector<int>> m;
vector<int> t[2];
int sum[2];

inline void Change(const int &iset, int x, const int &d) {
	sum[iset] += d;
	while (x <= ny) t[iset][x] += d, x += LB(x);
}

inline int M() {
	int r(INT_MAX), n0(0), n1(0), p(0);
	for (int i = 1 << __lg(ny); i; i >>= 1) {
		int s0 = n0 + t[0][min(ny, p + i)], s1 = n1 + t[1][min(ny, p + i)];
		if (max(s0, s1) <= max(sum[0] - s0, sum[1] - s1))
			p += i, n0 = s0, n1 = s1;
		else
			r = min(r, max(s0, s1));
	}
	return min(r, max(sum[0] - n0, sum[1] - n1));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int i, j, r(INT_MAX), x[n], y[n], vy[n];
	map<int, int> my;
	for (i = 0; i < n; ++i) cin >> x[i] >> y[i], vy[i] = y[i];
	sort(vy, vy + n);
	ny = unique(vy, vy + n) - vy;
	for (i = 0; i < 2; ++i) t[i].assign(ny + 1, 0);
	for (i = 0; i < ny; ++i) my[vy[i]] = i + 1;
	for (i = 0; i < n; ++i) j = my[y[i]], m[x[i]].emplace_back(j), Change(1, j, 1);
	for (auto it = m.begin(); it != m.end(); ++it) {
		for (int x : it->second) Change(0, x, 1), Change(1, x, -1);
		r = min(r, M());
	}
	cout << r;
}