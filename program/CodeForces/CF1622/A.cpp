#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
	vector<int> A(3);
	for(auto &a :A) cin >> a;
	sort(A.begin(), A.end() );
	if((A[0] + A[1] == A[2]) || (A[0] == A[1] && A[2] %2 == 0) || (A[1] == A[2] && A[0] % 2 == 0)) return cout << "YES\n", void();
	cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) solve() ;	
    return 0;
}
