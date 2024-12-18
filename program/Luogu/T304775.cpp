#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 5e5 + 5;
#define int long long

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
    return x;
}

int n, m;
int a[maxn], b[maxn], c[maxn], p[maxn];
int q;
int sumb[maxn], sumc[maxn], suma[maxn], mina[maxn], pc[maxn], pb[maxn];


signed main() {
    n = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1; i <= n; i++) b[i] = read(), sumb[i] = sumb[i-1] + b[i];
    for(int i = 1; i <= n; i++) c[i] = read();
    for(int i = 1; i <= n; i++) suma[i] = min(a[i], suma[i-1] + b[i]);
    q = read();
    while(q--) {
        long long ans = sumb[n];
        m = read();
        for(int i = 1; i <= m; i++) p[i] = read(), pc[i] = pc[i-1] + c[p[i]], ans -= b[p[i]];
        for(int i = m; i >= 1; i--) pb[i] = pb[i+1] + b[p[i]];
        for(int i = 1; i <= m; i++) {
            ans = min(ans, suma[p[i]-1] + pc[i-1] + sumb[n] - sumb[p[i]-1] - pb[i]);
        }
         ans = min(ans, suma[n] + pc[m]);
        cout << ans << "\n";
        for(int i = 1;  i<= m; i++) pb[i] = pc[i] = 0;
    }
    return 0;
}