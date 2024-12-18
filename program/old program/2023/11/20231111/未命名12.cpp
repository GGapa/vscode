#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000 + 5;

int n, ans = -2e9;
int a[maxn], b[maxn];
bool used[maxn];

void dfs(int x, int sum) {
	if(x > n) {
		ans = max(ans, sum);
	}
	for(int i = 1; i <= n; i++) {
		if(used[i]) continue;
		used[i] = true;
		dfs(x+1, sum + a[x] == b[i] ? 0 :(a[x] < b[i] ? 1 : -1));
		used[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	dfs(1, 0);
	cout << ans << "\n";
	return 0;
}
