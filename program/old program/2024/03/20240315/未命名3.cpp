#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n, k; cin >> n >> k;
	string s; cin >> s;
	using VI = vector<int>;
	vector<VI> G(n + 1, VI(n + 1)), F(n + 1, VI(k + 1));
	 
	rep(i, 0, n - 1) for(int len = 1, j; len + i < n; len++) {
		j = i + len - 1;
		auto t = s.substr(i, len); if(t == "") continue;
		G[i][j]	= stoi(t);
	}
	
    return 0;
}

