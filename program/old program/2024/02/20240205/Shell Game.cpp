//Shell Game
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 100 + 5;

int n;
int a[N], b[N], c[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i] >> b[i] >> c[i];
    int ans = 0;
    rep(i, 1, 3){
        vector<int> nw(4);
        nw[i] = 1;
        int cnt = 0;
        rep(j, 1, n) {
            swap(nw[a[j]], nw[b[j]]);
            if(nw[c[j]] == 1) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}