#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int n;
int a[N];
int m, p1, s1, s2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    cin >> m >> p1 >> s1 >> s2;
    a[p1] += s1;
    ll v1, v2; v1 = v2 = 0 ;
    rep(i, 1, n) {
        v1 += 1ll * (i < m ? a[i] : 0) * (m - i);
        v2 += 1ll * (i > m ? a[i] : 0) * (i - m);
    }  
    ll t1, t2, mn = LLONG_MAX;
    int it;
    rep(i, 1, n) {
        t1 = v1, t2 = v2;
        t1 += 1ll * (i < m ? s2 : 0) * (m - i);
        t2 += 1ll * (i > m ? s2 : 0) * (i - m);
        ll t3 = abs(t1 - t2);
        if(t3 < mn) {mn = t3; it = i;}
    }
    cout << it << '\n';

    return 0;
}