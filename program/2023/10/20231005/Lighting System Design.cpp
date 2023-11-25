/*
Lighting System Design
https://www.luogu.com.cn/problem/UVA11400
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e3 + 5;

int n;
int f[maxn], sum[maxn];

struct Node {
    int v, k, c, l;
}a[maxn];



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n && n) {
        memset(sum, 0, sizeof(sum));
        memset(f, 0x3f3f3f, sizeof(f));
        f[0] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i].v >> a[i].k >> a[i].c >> a[i].l;
        }
        sort(a + 1, a + 1 + n, [](const Node& x, const Node& y){return x.v < y.v;});
        for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i].l;
        for(int i = 1; i <= n; i++) for(int j = 0; j < i; j++) 
            f[i] = min(f[i], f[j] + (sum[i] - sum[j]) * a[i].c + a[i].k );
        cout << f[n] << "\n";
    }
    return 0;
}