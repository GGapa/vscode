//[USACO20FEB] Triangles B
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 100 + 5;

int n;
int x[N], y[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int ans = 0;
    rep(i, 1, n) cin >> x[i] >> y[i];
    rep(i, 1, n) 
        rep(j, 1, n) 
            rep(k, 1, n) {
                if((x[i] == x[j]) && (y[j] == y[k])) 
                    ans = max(ans, abs(y[i] - y[j]) * abs(x[j] - x[k]));
            }
    cout << ans;
    return 0;
}