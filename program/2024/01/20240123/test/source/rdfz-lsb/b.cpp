#include <bits/stdc++.h>
using namespace std;

const int N = 805;
const int M = 105;
const int mod = 1e9 + 7;
const long long inf = 9e16;

int q, tot;
long long ans;
int n[2], fa[N][2], deg[N][2], son[N][N][2], son_[N][N][2], len[N][N][2], cnt[N][N], val[M], mx[N];
long long f[N][N];
set<int> s;

void dfs(int u, int j) {
    for (int i = 1; i <= deg[u][j]; i++) {
        int v = son[u][i][j], l = 1;
        while (deg[v][j] == 1) {
            v = son[v][1][j];
            l++;
        }
        son_[u][i][j] = v;
        len[u][i][j] = l;
        dfs(v, j);
    }
}

bool tg(int u, int v) {
    if (deg[u][0] != deg[v][1]) {
        return 0;
    }
    bool res = 1;
    for (int i = 1; i <= deg[u][0]; i++) {
        res &= tg(son_[u][i][0], son_[v][i][1]);
    }
    return res;
}

void getmx(int u, int v) {
    for (int i = 1; i <= deg[u][0]; i++) {
        int u_ = son_[u][i][0], v_ = son_[v][i][1];
        getmx(u_, v_);
        int lu = len[u][i][0], lv = len[v][i][1];
        mx[lu] = max(mx[lu], lv);
    }
}

void cal(int u, int v) {
    for (int i = 1; i <= deg[u][0]; i++) {
        int u_ = son_[u][i][0], v_ = son_[v][i][1];
        cal(u_, v_);
        ans = f[len[u][i][0]][len[v][i][1]] % mod * ans % mod;
    }   
}

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    for (int j = 0; j < 2; j++) {
        cin >> n[j];
    }
    for (int j = 0; j < 2; j++) {
        fa[1][j] = n[j] + 1;
        son[n[j] + 1][++deg[n[j] + 1][j]][j] = 1;
        for (int i = 2; i <= n[j]; i++) {
            cin >> fa[i][j];
            int u = fa[i][j];
            son[u][++deg[u][j]][j] = i;
        }
        dfs(n[j] + 1, j);
    }
    cin >> q;
    if (!tg(n[0] + 1, n[1] + 1)) {
        for (int i = 1; i <= q; i++) {
            int op, x;
            cin >> op >> x;
            cout << "0\n";
        }
        return 0;
    }
    getmx(n[0] + 1, n[1] + 1);
    for (int i = n[0]; i >= 1; i--) {
        mx[i] = max(mx[i], mx[i + 1] - 1);
    }
    for (int i = 1; i <= q; i++) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            s.insert(x);
        }
        else {
            s.erase(x);
        }
        tot = 0;
        for (int v : s) {
            val[++tot] = v;
        }
        ans = 1;
        f[0][0] = 1;
        for (int j = 1; j <= n[0]; j++) {
            int t = mx[j];
            for (int k = 1; k <= t; k++) {
                f[j][k] = 0;
            }
            for (int l = 1; l <= tot; l++) {
                int x = val[l];
                for (int k = x; k <= t; k++) {
                    f[j][k] += f[j - 1][k - x];
                }
            }
            for (int k = 1; k <= t; k++) {
                if (f[j][k] >= inf) {
                    f[j][k] %= mod;
                }
            }
        }
        cal(n[0] + 1, n[1] + 1);
        cout << ans << '\n';
    }

    return 0;
}