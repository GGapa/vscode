#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 3e6 + 5;

int idx = 0;
int T[N][2];

void insert(int x) {
    int t = 0;
    per(i, 30, 0) {
        int c = (x >> i) & 1;
        if(!T[t][c]) T[t][c] = ++idx;
        t = T[t][c];
    }
}

int F[N];

void dfs(int x, int dep) {
    auto &f = F[x];
    int lc = T[x][0], rc = T[x][1];
    if(lc) dfs(lc, dep + 1);
    if(rc) dfs(rc, dep + 1);
    if(lc + rc == max(lc, rc)) return f = F[max(lc, rc)], void();
    int t = (30 - dep) - 1;
    f = min(F[lc], F[rc]) + (1 << t);
    return ;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        insert(x);
    }
    dfs(1, 0);
    cout << F[1] << '\n';
    return 0;
}