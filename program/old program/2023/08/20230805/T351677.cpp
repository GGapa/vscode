//T351677 「RiOI-2」change
//https://www.luogu.com.cn/problem/T351677?contestId=122184
//
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
#define ll unsigned long long
#define int unsigned long long
const int maxn = 2e5 + 5;
const int mod = 998244353;
int sid, n, T;

inline void print(__uint128_t x) {
    if(x < 0) {
        putchar('-');
        x *= -1;
    }
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
namespace General {
    int Main(){
        cin >> T;
        while(T--) {
            cin >> n;
            vector <int> V(n), C(n), X(n - 1);
            for(auto i : V) cin >> i;
            for(auto i : C) cin >> i;
            for(auto i : X) cin >> i;
        }
    }
}
namespace sid1 {
    int Main(){
        cin >> T;
        while(T--) {
            cin >> n;
            vector <int> V(n), C(n), X(n - 1);
            for(int i = 0; i < n; i++) cin >> V[i];
            for(int i = 0; i < n; i++) cin >> C[i];
            for(int i = 0; i < n - 1; i++) cin >> X[i];
            __uint128_t ans = 0;
            for(int i = 0; i < n; i++) {
                if(C[i] >= X[i] && V[i] * C[i] <= V[i + 1]) {
                    C[i] -= 1e9;
                    C[i + 1] += 1;
                }
                ans += ((ll)V[i] % mod) * ((ll)C[i] % mod);
            }
            ans %= mod;
            print(ans);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> sid;
    //General::Main();
    if(sid == 0) {
        sid1::Main();
        return 0;
    }
    return 0;
}