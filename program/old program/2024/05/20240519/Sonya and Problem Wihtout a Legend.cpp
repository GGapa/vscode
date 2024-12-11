// Sonya and Problem Wihtout a Legend
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int INF = 1e18;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> A, X;
    for(int i = 1, x; i <= n; i++) cin >> x, A.emplace_back(x), X.emplace_back(x), X.emplace_back(x - 1);
	sort(X.begin(), X.end()); X.erase(unique(X.begin(), X.end()), X.end());
	// X.insert(X.begin(), X[0] - 1);
	int m = X.size();
	vector<VI> F(2, VI(m, INF));
	rep(i, 0, m - 1) F[0][i] = abs(A[0] - X[i]);
	rep(i, 1, n - 1) {
		int t = i % 2, t1 = t ^ 1;
		fill(F[t].begin(), F[t].end(), INF);
		int r = 0;
		list<int> q;
		rep(j, 0, m - 1) {
			while(r < m && X[r] < X[j]) {
				while(!q.empty() && F[t1][q.back()] > F[t1][r]) q.pop_back();
				q.push_back(r++);
			}
			// cout << q.size() << '\n';
			if(F[t1][q.front()] < INF) {
				F[t][j] = F[t1][q.front()] + abs(A[i] - X[j]);
			}
		}
		// rep(i, 0, m - 1) cout << X[i] << " " << F[t][i] << '\n';
		// cout << "\n";
	}
	cout << *min_element(F[(n - 1) % 2].begin(), F[(n - 1) % 2].begin() + m) << '\n';
    return 0;
}
/*
考虑将所有数字离散化，定义 F[i][j] 
对第 i 个数字进行操作，将其变为 j 且 1 - i 满足不降序列的最小操作次数。
可以使用滚动数组优化。
*/