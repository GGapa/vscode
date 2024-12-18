//P2158 [SDOI2008] 仪仗队
//https://www.luogu.com.cn/problem/P2158
#include <iostream>
#include <bitset>
using namespace std;
const int maxn = 40000 + 5;
bitset<maxn> vis;
int p[maxn], Phi[maxn], N;
int main() {
    cin >> N;
    if(N == 1) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for(int i = 2; i < N; i++) {
        int m = i, t = i;
        for(int j = 2; j * j <= t; j++) {
            if(t % j == 0) {
                m -= m / j;
                while(t % j == 0) t /= j;
            }
        }
        if( t > 1) m -= m / t;
        ans += m;
    }
    cout << ans * 2 + 3 << endl;
    return 0;
}