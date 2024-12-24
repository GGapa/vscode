#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 4e5 + 1;

LL S[N];
int stk[N], ans[N];
int n;
pair<int, int> opstk[N];

int h1[N], t1[N], n1[N], c1 = 0, i1[N];
void ad1(int u, int v) {
    t1[++c1] = v;
    n1[c1] = h1[u];
    h1[u] = c1;
}

void ad2(int u, int v, int id) {
    t1[++c1] = v;
    i1[++c1] = id
    n1[c1] = h1[u];
    h1[u] = c1;
}

int l, r, res;
void dfs(int x) {
    stk[++stk[0]] = x;
    for(int i = h1[x]; i; i = n1[i]) dfs(t1[i]);
    stk[0]--;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> ans[i], S[i] = S[i - 1] + ans[i];

    sort(S + 1, S + 1 + n);
    int m = unique(S + 1, S + 1 + n) - S;
    LL sum = 0;
    rep(i, 1, n) sum += ans[i], ans[i] = lower_bound(S + 1, S + 1 + n, sum) - S;

    for(int i = 1, mx = 0; i <= n; i++) {
        mx = max(mx, stk[ans[i]]);
        stk[ans[i]] = i;
        ad1(mx, i);
    }

    int q; cin >> q;
    rep(i, 1, q) {
        cin >> l >> r;
        ad2(r, l, i);
    }

    stk[0] = 0;
    dfs(0);
    return 0;
}