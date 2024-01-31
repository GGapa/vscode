#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define int long long

int q[N], a[N], b[N], n;
int ans = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> q[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    
    for(int i = 0; ; i++) {
        int tmp = INT_MAX;
        for(int j = 1; j <= n; j++) {
            if(q[j] < i * a[j]) {
                cout << ans;
                return 0;
            }
            if(b[j] == 0)  continue;
            tmp = min(tmp, (q[j] - i * a[j]) / b[j]);
        }
        if(tmp == INT_MIN) break;
        ans = max(ans, i + tmp);
    }
    return 0;
}