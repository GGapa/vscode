#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;
int p;

map<int, int> mp;
int ans = INT_MAX;

LL qpow(LL x, LL y){
    LL ret=  1;
    for(; y; y >>= 1) {
        if(y & 1) (ret = ret * x) %= p;
        (x = x * x) %= p;
    }
    return ret;
}

void BS(int b, int n) {
    int t = ceil(sqrt(p));
    rep(i, 0, t) {
        if(!mp[n]) mp[n] = i;
        n = 1ll * n * b % p;
    }
}

void GS(int b, int n) {
    int t = ceil(sqrt(p));
    int pw, t2; pw = t2 = qpow(b, t);
    rep(i, 1, t) {
        if(mp.count(pw)) ans = min(ans, 1ll * i * t - mp[pw]) ;
        (pw *= t2) %= p;
    }
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int b, n;
    cin >> p >> b >> n;
    BS(b, n); GS(b, n);
    if(ans < INT_MAX) cout  << ans << '\n';
    else cout << "no solution\n";
    return 0;
}