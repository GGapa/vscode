#include<bits/stdc++.h>
#define int long long 
#define debug(a) cout << #a << '=' << a << '\n' 
using namespace std;
const int maxn = 2e5 + 10;

int T, n, f, a, b; // a 为 开机速度 b 为关机所需电量
int s[maxn];
void solve() {
    int ans = 0;
    cin >> n >> f >> a >> b;
    for(int i = 1; i <= n; i++)
      cin >> s[i];
    for(int i = 1; i <= n; i++) {
        ans += min((s[i]-s[i-1])*a, b); 
        if(ans >= f) {
        cout << "No" << '\n';
        return ;
        }
    }
    if(ans < f) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

signed main() {
    cin >> T;
    while(T--)
      solve();
    return 0;
}