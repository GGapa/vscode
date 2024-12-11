//Find a multiple
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 10000 + 5;

int n;
int s[N], m[N];

void out(int l, int r) {
    cout << r - l + 1 << '\n';
    rep(i, l, r) cout << s[i] - s[i - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n; s[0] = 0;
    for(int i = 1, x; i <= n; i++) cin >> x, s[i] = s[i - 1] + x;
    rep(i, 1, n)  {
        int r = s[i] % n;
        if(r == 0) {
            out(1, i);
            return 0;
        }
        if(m[r]) {
            out(m[r] + 1, i);
            return 0;
        }
        m[r] = i;
    }
    return 0;
}