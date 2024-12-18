//Minimum Sum LCM
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long

int n;

int solve() {
    int k = 0, po, ans = 0;
    for(int i = 2; i * i <= n; i++) {
        po = 0;
        if(n % i == 0) {
            k++;
            po = 1;
        }
        while(n % i == 0) {
            n /= i;
            po *= i;
        }
        ans += po;
    }
    if(n > 1) ans += n, k++;
    if(k == 1) ans++;
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cnt = 0;
    while(1)  {
        cin >> n; if(n == 0) break;
        if(n == 1) printf("Case %lld: 2\n", ++cnt);
        else printf("Case %lld: %lld\n", ++cnt, solve());
    }
    return 0;
}