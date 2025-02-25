#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int N = 1e6 + 5;

string s;
int n;
int sa[N], rk[N], ork[N], id[N], buc[N];

void SA() {
    int p = 0, m = 1 << 7;
    rep(i, 1, n) buc[rk[i] = s[i]]++;
    rep(i, 1, m) buc[i] += buc[i - 1];
    per(i, n, 1) sa[buc[rk[i]]--] = i;
    for(int w = 1; ; m = p, p = 0, w <<= 1) {
        rep(i, n - w + 1, n) id[++p] = i;
        rep(i, 1, n) if(sa[i] > w) id[++p] = sa[i] - w;
        memset(buc, 0, (m + 1) * sizeof(int));
        memcpy(ork, rk, (n + 1) * sizeof(int));
        p = 0;
        rep(i, 1, n) buc[rk[i]]++;
        rep(i, 1, m) buc[i] += buc[i - 1];
        per(i, n, 1) sa[buc[rk[id[i]]]--] = id[i];
        rep(i, 1, n) rk[sa[i]] = ork[sa[i - 1]] == ork[sa[i]] && ork[sa[i - 1] + w] == ork[sa[i] + w] ? p : ++p;
        if(p == n) return ;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> s;
    n = s.size(); s =  " " + s;
    SA();
    rep(i ,1, n) cout << sa[i] << " \n"[i == n];
    return 0;
}