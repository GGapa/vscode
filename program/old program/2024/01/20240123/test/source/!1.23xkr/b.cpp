#include<bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#define int long long
using namespace std;
const int maxn = 805, mod = 1e9 + 7;
int n, m, q, heige;
vector<int> a[maxn], b[maxn];
set<int> s;
int d[maxn], len;
struct qry {int n, m;} f[maxn];
int cnt;
int hg[maxn];
int dp[maxn];
int tmp[maxn];
int query(int n, int m) {
    for (int i = 0; i <= m; i++) dp[i] = 0;
    dp[0] = 1;
    for (int i = 0; i <= m; i++) tmp[i] = 0;
    for (int i = 1; i <= len; i++) 
        if (d[i] <= m) tmp[d[i]] = 1;
    while (n) {
        if (n & 1) {
            for (int i = 0; i <= m; i++) hg[i] = dp[i], dp[i] = 0;
            for (int i = 0; i <= m; i++)
                for (int j = 0; j <= m - i; j++)
                    dp[i + j] = (dp[i + j] + hg[i] * tmp[j]) % mod;
        }
        for (int i = 0; i <= m; i++) hg[i] = tmp[i], tmp[i] = 0;
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= m - i; j++)
                tmp[i + j] = (tmp[i + j] + hg[i] * hg[j]) % mod;
        n >>= 1;
    }
    return dp[m];
}
bool dfs(int p, int q) {
    int l1 = 1, l2 = 1;
    while (a[p].size() == 1) p = a[p][0], l1++;
    while (b[q].size() == 1) q = b[q][0], l2++;
    if (a[p].size() != b[q].size()) return 0;
    f[++cnt] = (qry){l1, l2};
    for (int i = 0; i < a[p].size(); i++)
        if (!dfs(a[p][i], b[q][i])) return 0;
    return 1;
}
int work() {
    if (!heige) return 0;
    len = 0;
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) d[++len] = *it;
    int ans = 1;
    for (int i = 1; i <= cnt; i++) ans = 1ll * ans * query(f[i].n, f[i].m) % mod;
    return ans;
}
signed main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        a[x].push_back(i);
    }
    for (int i = 2; i <= m; i++) {
        int x; cin >> x;
        b[x].push_back(i);
    }
    heige = dfs(1, 1);
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int p, x; cin >> p >> x;
        if (p == 1) s.insert(x);
        else s.erase(x);
        cout << work() << '\n';
    }
    return 0;
} 