//Bovine Genomics 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 500 + 5;

int n, m;
string s1[N], s2[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
// #ifdef ONLINE_JUDGE
freopen("cownomics.in", "r", stdin);
freopen("cownomics.out", "w", stdout);
// #endif
    cin >> n >> m;
    rep(i, 0, n - 1) cin >> s1[i];
    rep(i, 0, n - 1) cin >> s2[i];
    int ans = 0;
    rep(i, 0, m - 1) rep(j, i + 1, m - 1) rep(k, j + 1, m - 1) {
        unordered_set<string> us;
        rep(x, 0, n - 1) us.insert({s1[x][i], s1[x][j], s1[x][k]});
        bool tag = 1;
        rep(x, 0, n - 1) if(us.count({s2[x][i], s2[x][j], s2[x][k]})) {
            tag = false;
            break;
        }
        ans += tag;
    }
    cout << ans << '\n';
    return 0;
}