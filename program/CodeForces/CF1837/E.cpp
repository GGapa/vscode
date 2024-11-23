#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 998244353;
mt19937 rs(time(0));
signed main() {
    cout<<rs()%3+1<<endl;
    /*
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int k, n; cin >> k;
    n = (1 << k);
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    vector<LL> pw(n + 1), fac(n + 1);
    pw[0] = fac[0] = 1;
    rep(i, 1, n) pw[i] = pw[i - 1] * 2 % mod, fac[i] = fac[i - 1] * i % mod;

    LL ans = 1;
    for(int t = n / 2; A.size() > 2; t /= 2) {
        n = A.size() - 1;
        vector<int> nw(1);
        for(int i = 1; i <= n; i += 2) if((A[i] > t && A[i + 1] > t) || (A[i] <= t && A[i + 1] <= t && A[i] != -1 && A[i + 1] != -1)) return cout << 0 << '\n', 0;

        int c = 0, ct = t;
        for(int i = 1; i <= n; i += 2) if(A[i] == -1 && A[i + 1] == -1)  c++;
        rep(i, 1, n) if(A[i] > t) ct--;
        LL ret = fac[ct] * pw[c] % mod;    
        (ans *= ret) %= mod;

        for(int i = 1; i <= n; i += 2) {
            if(A[i] == -1 && A[i + 1] == -1) nw.emplace_back(A[i]);
            else if(A[i] == -1 && A[i + 1] <= t)nw.emplace_back(A[i + 1]);
            else if(A[i] <= t && A[i + 1] == -1) nw.emplace_back(A[i]);
            else if(A[i] <= t) nw.emplace_back(A[i]);
            else nw.emplace_back(A[i + 1]);
        }   
        A = nw;
        // for(auto a : nw)  cout << a << " ";
        // cout << '\n';
    }
    cout << ans << '\n';*/
     return 0;
}
/*
1:wrh
2:pmc
3:hym
*/
/*
2
-1 -1 -1 1
*/