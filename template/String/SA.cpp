#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
constexpr int N = 1e6 + 5;
 
string s; 
int sa[N], rk[N], ork[N], buc[N], id[N];
int n;
 
void SA() {
    int m = 1 << 7, p = 0;
    rep(i, 1, n) buc[rk[i] = s[i]]++;
    rep(i, 1, m) buc[i] += buc[i - 1];
    per(i, n, 1) sa[buc[rk[i]]--] = i;
    for(int w = 1; ; m = p, p = 0, w <<= 1) {
        rep(i, n - w + 1, n) id[++p] = i;
        rep(i, 1, n) if(sa[i] > w) id[++p] = sa[i] - w;
        memset(buc, 0, m + 1 << 2);
        memcpy(ork, rk, n + 1 << 2) ;
        p = 0;
        rep(i, 1, n) buc[rk[i]]++;
        rep(i, 1, m) buc[i] += buc[i - 1];
        per(i, n, 1) sa[buc[rk[id[i]]]--] = id[i];
        rep(i ,1, n) rk[sa[i]] = ork[sa[i - 1]] == ork[sa[i]] && ork[sa[i - 1] + w] == ork[sa[i] + w] ? p : ++p;
        if(p == n) return ;
    }
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s; 
    n = s.size(); s = " " + s;
    SA();
    rep(i, 1, n) cout << sa[i] << " \n"[i == n];
    return 0;
}