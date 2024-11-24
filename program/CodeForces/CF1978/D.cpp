//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    int n, c; cin >> n >> c;
    vector<int> A(n + 1), S(n + 1), mx(n + 1);
    rep(i, 1, n) cin >> A[i];
    S[1] = A[1] + c;
    rep(i, 2, n) S[i] = S[i - 1] + A[i];
    multiset<int> s(A.begin(), A.end()), tmp = s;
    rep(i, 1, n) mx[i] = max(mx[i - 1], A[i]);
    int spit = 1;
    rep(i, 1, n) if(A[i] > A[spit] && (i != 1 && A[i] > A[1] + c)) spit = i;
    rep(i, 1, n) {
        if(i == spit) {
            cout << 0 << " \n"[i == n];
            s.erase(s.find(A[i]));
            continue;
        }
        int out = i - 1;
        int sum = S[i];
        // tmp = s;
        for(auto i = s.rbegin(); i != s.rend() && sum < *i; i++) {
            out++;
            sum += *i;
        }
        s.erase(s.find(A[i]));
        cout << out << " \n"[i == n];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
在他之前的人获得了不定票数之后不能比他大。否则他就将获得不定票数，
在删除大票数之前要将它前面的全部叉掉，
*/