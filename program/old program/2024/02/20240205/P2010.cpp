//P2010 [NOIP2016 普及组] 回文日期

#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int n, m;
int s[13]={0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int ans = 0;
    rep(i, 1, 12) {
        rep(j, 1, s[i]) {
            int t = (j % 10) * 1000 + (j / 10) * 100 + (i % 10) * 10 + (i / 10);
            int t1 = t * 10000 + i * 100 + j;
            if(n <= t1 && t1 <= m) ans++;

        }
    }
    cout << ans << '\n';
    return 0;
}