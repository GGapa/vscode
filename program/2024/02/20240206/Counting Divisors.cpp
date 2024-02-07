//Counting Divisors
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        int ans = 0;
        for(int i = 1; i * i <= x; i++) if(x % i == 0)
            ans += (i == x / i ? 1 : 2);
        cout << ans << '\n';
    }
    return 0;
}