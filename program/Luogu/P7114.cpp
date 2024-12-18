#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

struct BIT {
    int n;
    vector<int> T;
    BIT(int _n) : n(_n) ,T(_n + 5) {    };
    int lowbit(int x) {return x & -x;}
    void add(int x, int v) {
        for(x; x <= n; x += lowbit(x)) T[x] += v;
    }
    ll ask(int x) {
        ll res = 0;                      
        for(; x > 0; x -= lowbit(x)) res += T[x];
        return res;
    }
};

vector<int> cnt(27), pre(27), suf(26 + 1);

void solve() {
    string s; cin >> s;
    BIT T(27);
    int n = s.size(); s = " " + s;
    fill(cnt.begin(), cnt.end(), 0);
    fill(pre.begin(), pre.end(), 0);
    fill(suf.begin(), suf.end(), 0);
    vector<int> z(n + 1); z[0] = n;
    for(int i = 2, l = 0, r = 0; i <= n; i++) {
        int &j = z[i] = i > r ? 0 : min(r - i + 1, z[i - l + 1]);
        while(s[1 + j] == s[i + j] && j < n) j++;
        if(i + j - 1 > r) r = i + j - 1, l = i;
    }

    int sum, pc, sc; sum = pc = sc = 0;
    rep(i, 1, n) cnt[s[i] - 'a']++;
    rep(i, 0, 26) sum += (cnt[i] & 1);
    rep(i, 1, n) if(z[i] + i - 1== n) z[i]--;
    sc = sum; suf = cnt;
    ll ans =  0;
    rep(i ,1, n) {
        int c = s[i] - 'a';
        if(pre[c] & 1) pc--;
        else pc++;
        pre[c]++;
        if(suf[c] & 1) sc--;
        else sc++;
        suf[c]--;
        if(i != 1 && i != n) {
            int t = z[i + 1] / (i) + 1;
            ans += 1ll * (t / 2) * T.ask(sum + 1) + 1ll * (t - t / 2) * T.ask(sc + 1);
        }
        T.add(pc + 1, 1);
    }
    cout << ans << '\n';
}

signed main() {
    // freopen("A.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
1 1
0 2
1 1
2 2
1 1
2 0
*/