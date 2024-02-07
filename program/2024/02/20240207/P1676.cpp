// P1676 [USACO05FEB] Aggressive cows G
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int n, m;
int a[N];

bool check(int x) {
    int cnt = 0;
    for(int l = 1, r = 1; l <= n && r <= n; l = r, cnt++) {
        while(a[r] - a[l] < x && r <= n) r++;
    } 
    return cnt >= m;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = 1, r = 1e9;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid ;
    }
    cout << l << '\n';
    return 0;
}