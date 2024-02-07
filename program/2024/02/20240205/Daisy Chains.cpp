//Daisy Chains
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;

int n;
int a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int ans = 0;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) rep(j, i, n) {
        int l = j - i + 1, s=  0;
        rep(k, i, j) s += a[k];
        rep(k, i, j) if(a[k] * l == s) {
            ans++;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}