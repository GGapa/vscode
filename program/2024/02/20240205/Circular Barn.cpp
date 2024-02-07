//Circular Barn
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;

int n, sum;
int a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans = INT_MAX;
    rep(i, 1, n) cin >> a[i], sum += a[i];
    rep(i, 1, n) {
        int d = 0;
        for(int j = 1, cnt = sum; j <= n; j++) cnt -= a[((i + j) % n) + 1], d += cnt;
        ans = min(ans , d); 
    }
    cout << ans << '\n';
    return 0;
}