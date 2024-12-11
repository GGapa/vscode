#include <iostream>
using namespace std;
const int maxn = 5e6 + 5;
typedef long long ll;
#define int long long
int n, p, k, a[maxn];
ll s, pre[maxn], suf[maxn], ans = 0;

ll qpow(int x, int y) {
    int ans = 1, base = x;
    while(y != 0) {
        if(y & 1) ans = (ans * base) % p;
        base = (base * base) % p;
        y >>= 1;
    }
    return ans;
}

int Inv(int x){
    if(x == 1)return 1;
    return((p - p/x) * Inv(p%x) % p);
}

int read() {
    int f = 1, x = 0;
    char c;
    c = getchar();
    while(!isdigit(c)) {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(isdigit(c)) {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return f * x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("AKIOI.in", "r", stdin);
    // freopen("AKIOI.out", "w", stdout);
    n = read(); p = read(); k = read();
    pre[0] = 1;
    suf[n+1] = 1;
    for(int i = 1; i <= n; i++) a[i] = read(), pre[i] = (pre[i-1] * a[i]) % p;
    for(int i = n; i >= 1; i--) suf[i] = (suf[i+1] * a[i]) % p;
    ll ki = k;
    for(int i = 1; i <= n; i++, ki = (k * ki) % p) {
        ans = (ans + ki * pre[i-1] % p * suf[i+1] % p) % p;
    }
    cout << ans * Inv(pre[n]) % p ;
    return 0;
}