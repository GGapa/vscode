//Count 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 1000 + 5;
const int mod = 1e9 + 7;

int n;
ll a[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    a[0] = a[1] = a[2] = 1;
    rep(i, 3, N - 1) rep(j, 1, i - 1) 
        if((i - 1) % j == 0) (a[i] += a[j]) % mod;
    for (int n, t = 1; scanf("%d", &n) == 1; t++)
        printf("Case %d: %lld\n", t, a[n] % mod);
    return 0;
}