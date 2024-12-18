#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;    
    vector<int> x(n);
    rep(i, 0, n - 1) cin >> x[i];
    vector<string> ss(n);
    rep(i, 0, n - 1) cin >> ss[i];
    int tp = (1 << n) - 1;
    int ans = -1;
    vector<int> out(m);
    rep(s, 0, tp) { //1 + 0 - 
        int sum = 0;
        rep(i, 0, n - 1)  sum += (((s >> i) & 1) == 1 ? -1 : 1) * x[i]; 
        vector<int> A(m);   
        rep(i ,0, n - 1) rep(j, 0, m - 1) {
            if(ss[i][j] == '0') continue;
            A[j] += ((((s >> i) & 1) ) == 1 ? 1 : -1);
        }
        vector<int> B(m);
        iota(B.begin(), B.end(), 0);
        sort(B.begin(), B.end(), [&](const int &x, const int &y ){
            return A[x] < A[y];
        });
        rep(i, 0, m - 1) sum += A[B[i]] * (i + 1); 
        // cout << bitset<10>(s) << " " << sum << '\n';
        if(sum > ans) {
            ans = sum;
            rep(i, 0, m - 1) out[B[i]] = i + 1;
        }
    }
    rep(i, 0, m - 1) cout << out[i] << " \n"[i == m - 1];
} 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}