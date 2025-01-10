#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int mod = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1), F(n + 1), S(n + 1), vis(n + 1);
    rep(i ,1, n) cin >> A[i];
    set<int> s;
    
    F[0] = 1;
    auto check = [&](int i) {return i - 1 >= 1 && i + 1 <= n && A[i - 1] != A[i] && A[i] != A[i + 1]; };
    s.insert(A[1]);
    for(int i = 1, l = 0, r = 1; i <= n; i++) {
        (F[i] += F[i - 1]) %= mod;
        if(check(i - 1)) (F[i] += F[i - 2]) %= mod;

        vis[A[i]]++;
        if(vis[A[i]] >= 1) s.insert(A[i]);
        if(A[i] == A[i - 1]) l = i - 1;
        while(s.size() >= 3 && r < i - 2) {
            vis[A[r]]--;
            if(vis[A[r]] == 0) s.erase(A[r]);
            r++;
        }
        if(l < r) (F[i] += (S[r - 1] - S[l] + mod) % mod) %= mod;
        S[i] = (S[i - 1] + F[i]) % mod;
    }
    cout << F[n] << '\n';
    return 0;   
}