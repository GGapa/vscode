//P3143 [USACO16OPEN] Diamond Collector S
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    rep(i, 1, n) rep(j, i + 1, n) {
        if(a[j] - a[i] <= k) 
            ans = max(ans, j - i + 1);
        else 
            break;
    }
    cout << ans << '\n';
    return 0;
}
//1 5 5 9 10 12 14
