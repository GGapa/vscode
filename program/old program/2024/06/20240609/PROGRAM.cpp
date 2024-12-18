//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> A(n), cnt(n + 1);
    for(int i = 1, x; i <= m;i ++)   {
        cin >> x;   
        cnt[x]++;
    } 
    rep(i, 1, n) if(cnt[i]){
        for(int j = 0; j < n; j += i) 
            A[j] += cnt[i];
    }
    vector<ll> sum(n + 1);
    rep(i, 0, n - 1) sum[i] = (i == 0 ? 0 : sum[i - 1]) + A[i];
    int q; cin >> q;
    for(int l, r, o = 1; o <= q; o++) {
        cin >> l >> r;
        cout << sum[r] - (l == 0 ? 0 : sum[l - 1]) << "\n";
    }
    return 0;
}