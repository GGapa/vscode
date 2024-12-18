#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
string s;
char ans[N][N];
int tp, st[N];
int ls[N], rs[N];
int dep[N], pos[N], MX, mcl[N], mcr[N];
int solve (int x, int l, int r) {
	if (l == r) {
		dep[l] = dep[x] + 2;
		ans[dep[l]][pos[l]] = s[l];
		return l;
	}
	int y = -1, fl = 0;
	if (s[l] == '(' && r + 1 == mcr[l])
	return solve(x, l + 1, r - 1);
	for (int i = mcl[r]; i >= l; i = mcl[i - 1]) {
		if (y != -1) break;
		if (s[i] == '+' || s[i] == '-') y = i;
	}
	for (int i = mcl[r]; i >= l; i = mcl[i - 1]) {
		if (y != -1) break;
		if (s[i] == '*' || s[i] == '/') y = i;
	}
	for (int i = mcr[l]; i <= r; i = mcr[i + 1]) {
		if (y == -1 && s[i] == '^') y = i;
	}
	dep[y] = dep[x] + 2;
	ls[y] = solve(y, l, y - 1);
	rs[y] = solve(y, y + 1, r);
	int d = dep[y], p = pos[y], pl = pos[ls[y]], pr = pos[rs[y]];
	ans[d][p - 1] = '[';
	ans[d][p] = s[y];
	ans[d][p + 1] = ']';
	ans[d][pl] = '.';
	ans[d + 1][pl] = '|';
	for (int i = pl + 1; i < p - 1; ++i)
	ans[d][i] = '-';
	ans[d][pr] = '.';
	ans[d + 1][pr] = '|';
	for (int i = p + 2; i < pr; ++i)
	ans[d][i] = '-';
	MX = max(MX, dep[y]);
	return y;
}
bool check (char c) {
	if ('a' <= c && c <= 'z') return true;
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') return true;
	return false;
}
int main() {
	// freopen ("tree.in", "r", stdin);
	// freopen ("tree.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	s = " " + s;
	int n = s.size();
	int lst = 1;
	for (int i = 1; i <= n; ++i)
	mcl[i] = i, mcr[i] = i;
	for (int i = 1; i < n; ++i) {
		if (s[i] == '(') st[++tp] = i; else if (s[i] == ')') {
			mcl[i] = st[tp] - 1, mcr[st[tp]] = i + 1;
			tp--;
		}
		if (check(s[i])) {
			pos[i] = lst;
			lst += 3;
		}
	}
	;
	for (int i = 0; i <= 2000; ++i)
	for (int j = 0; j <= lst - 2; ++j)
	ans[i][j] = ' ';
	dep[0] = -1;
	solve(0, 1, n - 1);
	for (int i = 1; i <= MX + 2; ++i, cout << endl)
	for (int j = 1; j <= lst - 2; ++j)
	cout << ans[i][j];
	return 0;
}