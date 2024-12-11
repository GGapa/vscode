/*
P2840 纸币问题 2
https://www.luogu.com.cn/problem/P2840
CSP2023 rp++
*/

#include <iostream>
using namespace std;
const int maxn = 1e3 + 5;
const int maxw = 1e4 + 5;
const int mod = 1e9 + 7;
typedef long long ll;

int n, w;
int a[maxn];
ll f[maxw];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    f[0] = 1;
    for(int i = 1; i <= w; i++) {
        for(int j = 1; j <= n; j++) {
            if(i >= a[j]) f[i] = f[i] + f[i - a[j]] % mod;
        }
    }
    cout << f[w] % mod << endl;
    return 0;
}