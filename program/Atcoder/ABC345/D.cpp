#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 15;
using AI = array<int, 2>;
vector<AI> a;
using VI = vector<int>;
// vector<VI> F(N + 1, VI(N  +1, -1));
vector<int> vis(N);
int n, h, w;

int dfs(int x, int y) {
    // cout << x << " " << y << '\n';
    if(x <= 0 || y <= 0) return 0;
    int f = 0;    
    rep(i, 0, n - 1) if(!vis[i]){
        int l = a[i][0], r = a[i][1];
        // if(min(l, r) == min(x, y) && max(l, r) == max(x, y)) return x * y;
        vis[i] = true;
        int t1 = (x - l >= 0 && y - r >= 0) ,t2 = (x - r >= 0 && y - l >= 0);
        int t = dfs(x - l, y);
            t += dfs(x, y - r);
        f = max(t1 * l * r + t, f);
        f = max(t2 * l * r + dfs(x - r, y) + dfs(x, y - l), f);
        vis[i] = false;
    }
    return f;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> h >> w;
    // int ss = 0;
    for(int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        // ss += x * y;
        if(x > y) swap(x, y);
        a.push_back({x, y});
    }
    // if(ss < h * w) return cout << "No\n", 0;
    cout << (dfs(h, w) == h * w ? "Yes\n" : "No\n");
    return 0;
}