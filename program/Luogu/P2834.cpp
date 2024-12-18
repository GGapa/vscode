/*
P2834 纸币问题 3
https://www.luogu.com.cn/problem/P2834\
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
    for(int i = 1; i <= n; i++) {
        for(int j = a[i]; j <= w; j++) {
            if(j >= a[i])f[j] = (f[j] + f[j - a[i]]) % mod;
        }
    }
    cout << f[w] << endl;
    return 0;
}