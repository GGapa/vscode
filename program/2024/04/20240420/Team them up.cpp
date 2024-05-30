// Team them up! UVA1627
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 100 + 5;
bool G[N][N];
int cc, n;
VI T[N][2], Dif(N);

bool dfs(int x, int c, VI &C) {
    C[x] = c, T[cc][c - 1].push_back(x);
    rep(to, 1, n) if(to != x && !(G[x][to] && G[to][x])) {
        if(C[to] > 0 && C[to] == C[x]) return false;
        if(C[to] == 0 && !dfs(to, 3 - c, C)) return false;
    }
    return true;
}

bool bulid() {
    VI C(n + 1);
    cc = 0;
    rep(i, 1, n) if(!C[i]) {
        cc++;
        T[cc][0].clear(); T[cc][1].clear();
        if(!dfs(i, 1, C)) return false;
        Dif[cc] = T[cc][0].size() - T[cc][1].size();
    }
    return true;
}

int D[N][N * 2];

void print(int x) {
    VI t1, t2;
    per(i, cc, 1) {
        int t = D[i][x - Dif[i] + n];
        x += (t == 1 ? -1 : 1) * Dif[i];
        for(auto u : T[i][t ^ 1]) t1.push_back(u);
        for(auto u : T[i][t]) t2.push_back(u);
    }
    cout << t1.size();
    for(auto i : t1) cout << " " << i;
    cout << '\n';
    cout << t2.size();
    for(auto i : t2) cout << " " << i;
    cout << '\n';
}

void dp() {
    VI t1, t2;
    memset(D, 0, sizeof(D));
    D[1][n] = 1;
    rep(i, 1, cc) rep(j, -n, n) if(D[i][j + n]) {
        D[i + 1][j + n + Dif[i]] = D[i + 1][j + n - Dif[i]] = 1;
    }
    rep(i, 0, n) {
        if(D[cc + 1][i + n]) 
            return print(i);
        if(D[cc + 1][-i + n]) 
            return print(i);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for(int ca = 1; ca <= T; ca++) {
        memset(G, 0, sizeof(G));

        if(ca != 1) cout << '\n';
        cin >> n;
        rep(i, 1, n) 
            for(int j; cin >> j && j;) G[i][j] = 1; 
        if(n == 1 || !bulid()) {
            cout << "No solution\n";
            continue;
        }
        dp();
    }
    return 0;
}