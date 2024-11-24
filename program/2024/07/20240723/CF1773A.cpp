//Amazing Trick
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

mt19937 rd(time(0));

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i ,1, n) cin >> A[i];
    vector<int> p(n + 1), q = p;
    iota(p.begin(), p.end(), 0); 
    rep(_, 1, 1000) {
        shuffle(p.begin() + 1, p.end(), rd);
        bool tag = true;
        rep(i ,1, n) {
            if(p[i] == i || A[p[i]] == i) {
                tag= false;
                break;
            }
            q[A[p[i]]] = i;
        }
        if(tag) {
            cout << "Possible\n";
            rep(i, 1, n) cout << p[i] << " \n"[i == n];
            rep(i ,1, n) cout << q[i] << " \n"[i == n];

            return ;
        }
    } 
    cout << "Impossible\n";
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}