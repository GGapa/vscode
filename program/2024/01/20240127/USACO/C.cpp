#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

ll a[N], b[N], c[N];    
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ll ans = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] += b[i - 1];
        c[i] = c[i - 1] + b[i];
        a[i] = a[i] + c[i];
        ans += abs(a[i]);
        b[i] += -a[i];
        c[i] += -a[i];
    }
    cout << ans << '\n';
    return 0;
}
/*
1 3 -2 -7 5
0 1 -5 -11 0
0 0 -7 -14 -4
0 0 0 0 17

 */
