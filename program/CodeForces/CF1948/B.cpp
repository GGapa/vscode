#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    set<int> s;
    vector<int> A(n +1), fl = A;
    rep(i, 1, n) cin >> A[i];
    bool tag = true;
    s.insert(-1);
    int ls = 1;
    auto check = [&](int v) {
        bool bj = v >= *s.rbegin();
        s.insert(v);
        return bj;
    };
    rep(i, 1, n) {       
        if(A[i] < A[i - 1]) {
            rep(j, ls, i - 1) {
                string ss = to_string(A[j]);
                for(auto c : ss) 
                    tag &= check(c - '0');
            }
            ls = i;
            tag &= (*s.rbegin() <= A[i]);
        }
    }
    // rep(j, ls, n)  {
    //     string ss = to_string(A[j]);
    //                     for(auto c : ss) 
    //                         tag &= check(c - '0');
    // }
    cout << (tag ? "YES\n" : "NO\n");
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}