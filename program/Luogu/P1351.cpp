#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 10007;

int n;
vector<int> G[maxn];
int a[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("CSP2023rp++.im", "r", stdin);
    //freopen("CSP2023rp++.out", "w", stdout);
    cin >> n;
    for(int i = 2, u, v; i <= n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int sum = 0, ans = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        int he = 0, mul = 0;
        he = mul = a[G[i][0]];
        for(int j = 1; j < G[i].size(); j++){
            int to = G[i][j];
            sum = (sum + he * a[to]) % mod;
            ans = max(ans, mul * a[to]) ;
            he = (a[to] + he) % mod;
            mul = max(mul, a[to]);
        }

    }
    cout << ans << " " << (sum * 2) % mod << "\n";
    return 0;
}
