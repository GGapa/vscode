#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int mod = 1e9 + 7;

namespace pre {
    constexpr LL qpow(LL x, LL y){
        LL ret = 1;
        for(; y; y >>= 1) {
            if(y & 1) (ret = ret * x % mod);
            (x = x * x % mod) ;
        }
        return ret;
    }

    constexpr LL inv(LL x) {return qpow(x, mod - 2); }
}   
using namespace pre;

int F[1010][2];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n; char AA, AB, BA, BB;
    cin >> n >> AA >> AB >> BA >> BB;
    
    if (n == 2) return cout << 1 << '\n', 0;
    
    int ans;
    if (AB == 'A') {
        if (AA == 'A') ans = 1;
        else {
            if (BA == 'A') {
                F[1][0] = 1;
                for (int i = 1; i <= n - 2; ++ i ) {
                    F[i + 1][0] = (F[i][0] + F[i][1]) % mod;
                    F[i + 1][1] = F[i][0];
                }
                ans = F[n - 1][0];
            } else {
                ans = qpow(2, n - 3);
            }
        }
    } 
    else {
        if (BB == 'B') ans = 1;
        else {
            if (BA == 'B') {
                F[1][1] = 1;
                for (int i = 1; i <= n - 2; ++ i ) {
                    F[i + 1][1] = (F[i][0] + F[i][1]) % mod;
                    F[i + 1][0] = F[i][1];
                }
                ans = F[n - 1][1];
            } else {
                ans = qpow(2, n - 3);
            }
        }
    }
    
    cout << ans << '\n';    

    return 0;
}