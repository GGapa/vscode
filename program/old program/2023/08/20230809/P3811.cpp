//P3811 【模板】乘法逆元
//https://www.luogu.com.cn/problem/P3811
#include <iostream>
using namespace std;
#define int long long 
const int maxn = 3e6 + 5;
int n, p;
int inv[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p;
    inv[1] = 1;
    cout << "1\n";
    for(int i = 2; i <= n; i++) {
        inv[i] = (p - (p / i)) * inv[p % i] % p;
        cout << inv[i] << '\n';
    }
    return 0;
}