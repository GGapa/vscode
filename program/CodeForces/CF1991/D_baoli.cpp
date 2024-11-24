#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 2e5 + 5;
int c[N];
vector<int> G[N];
int n;

bool check(int x, int nc) {
    for(auto to : G[x]) if(c[to] == nc) return false;
    return true;
}

void dfs(int x, int mx) {
    if(x == n + 1) {
        rep(i ,1, n) cout << c[i] << " \n"[i == n];
        exit(0);
    }
    rep(i, 1, mx) if(check(x, i)) c[x] = i, dfs(x + 1, mx);
    c[x] = 0;
}

bool isprime(int x) {
    if(x == 1) return false;
    for(int i = 2; i * i <= x; i++) if(x % i == 0) return false;
    return true;
}

void init() {
    rep(i, 1, n) rep(j, i + 1, n) if(isprime(i ^ j)) G[i].push_back(j), G[j].push_back(i);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    init();
    for(int mx = 1; ; mx++)  dfs(1, mx);
    return 0;
}