//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 500 + 5;

int n;
int A[N][N], C[N * N];
vector<pair<int, int>> E;

int dfs(vector<int> ls) {
    if(ls.size() == 1) return ls[0];
    int res = -1;
    for(auto u : ls) res = max(res, A[ls[0]][u]);
    vector<VI> ch;
    ch.push_back({ls[0]});
    rep(i, 1, (int)ls.size() - 1) {
        int v = ls[i];
        int ret = -1;
        for(int j = 0; j < (int)ch.size(); j++) {
            if(A[v][ch[j][0]] != res){
                ret = j;
                break;
            }
        }
        if(ret == -1) {
            ret = ch.size();
            ch.push_back({});
        }
        ch[ret].push_back(v);
    }
    int v = n++;
    C[v] = res;
    for(int i = 0; i < (int)ch.size(); i++) {
        int u = dfs(ch[i]);
        E.push_back({u, v});
    }
    return v;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 0, n - 1) rep(j, 0, n - 1) cin >> A[i][j];
    rep(i, 0, n - 1) C[i] = A[i][i];
    vector<int> ls(n);
    iota(ls.begin(), ls.end(), 0);
    int rt = dfs(ls);
    cout << n << '\n';
    rep(i, 0, n - 1) cout << C[i] << " \n"[i == n - 1];
    cout << rt + 1 << '\n';
    for(auto e : E) cout << e.first + 1 << " " << e.second + 1<< '\n';
    return 0;
}