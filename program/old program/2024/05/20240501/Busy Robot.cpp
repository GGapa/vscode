// Busy Robot CF1463C
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    int n; cin >> n; 
    int ans = 0;
    vector<int> A(n + 2), B(n + 2);
    rep(i, 1, n) cin >> A[i] >> B[i];
    int lt = 0, ti = 0, u = 0, v = 0;
    A[n + 1] = 4e9;
    rep(i ,1, n) {
        if(A[i] - A[lt] >= ti) {
            ti = abs(B[i] - B[lt]);
            u = B[lt];
            v = B[i];
            lt = i; 
            if(i == n || abs(A[i + 1] - A[i]) >= ti) ans++;
        }
        else if((u <= B[i] && B[i] <= v && A[i] - A[lt] <= B[i] - u &&B[i] - u <= A[i + 1] - A[lt]) || (u >= B[i] && B[i] >= v && A[i] - A[lt] <= u - B[i] && u - B[i] <= A[i + 1] - A[lt]) ) ans++;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

// || (i == n && A[lt] + ti >= A[i] && ((u <= B[i] && B[i] <= v) || (v <= B[i] && B[i] <= u)))