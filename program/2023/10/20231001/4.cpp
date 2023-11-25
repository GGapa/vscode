#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits.h>
using namespace std;
const int maxn = 1e5 + 5;

int x[maxn], c[maxn];
int n;
int ans = INT_MAX;

void dfs(int it, int val, int cost) {
    if(it > n) return;
    if(val == 1) {
        ans = min(ans, cost);
    }
    int g = __gcd(val, x[it + 1]);
    dfs(it + 1, g, cost + c[it + 1]);
    dfs(it + 1, val, cost);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> x[i];
    for(int i = 1; i <= n; i++) 
        cin >> c[i];
    for(int i = 1; i <= n; i++) {
        dfs(i, x[i], c[i]);
    }
    if(ans != INT_MAX)cout << ans << endl;
    else cout << -1 << endl;
    return 0;

    return 0;
}