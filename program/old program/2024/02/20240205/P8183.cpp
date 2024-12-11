//[USACO22FEB] Sleeping in Class B
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int n;
int a[N];

void solve() {
    cin >> n;
    int sum = 0;
    rep(i, 1, n) cin >> a[i], sum += a[i];
    per(i, n, 1) {
        if(sum % i != 0) continue;
        int d = 0;
        bool tag = true;
        rep(j, 1, n) {
            d += a[j];
            if(d > sum / i) {
                tag = false;
                break;
            }
            if(d == sum / i) d = 0;
        }
        if(tag) {
            cout << n - i << '\n';
            return ;
        }
    }    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}