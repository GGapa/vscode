// E
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 4e5 + 5;

int T[N][27], idx = 0;
int cnt[N];

void insert(string s) {
    int n = s.size(); s = " " + s;
    int p = 0;
    rep(i, 1, n) {
        int &t = T[p][s[i] - 'a'];
        if(!t) t = ++idx;
        p = t;
        cnt[p]++;
    }
}

int ask(string s) {
    int n = s.size(); s = " " + s;
    int p = 0, res = 0;
    rep(i, 1, n) {
        int &t = T[p][s[i] - 'a'];
        if(!t) break;
        p = t;
        res += cnt[p]; 
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    ll ans = 0;
    rep(i, 1, n) {
        string s; cin >> s;
        ans += ask(s);
        insert(s);
    }
    cout << ans << '\n';
    return 0;
}