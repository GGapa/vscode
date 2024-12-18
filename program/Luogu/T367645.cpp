/*
T367645 Prime.
https://www.luogu.com.cn/problem/T367645?contestId=126183
*/
#include <iostream>
using namespace std;
const int mod = 998244353;
const int maxn = 100000 + 5;
const int maxm = 1e9 + 5;
typedef unsigned long long ll;
int n, m;
int prime[maxn];
ll phi[maxn];
void Euler() {
    bool is_prime[maxn];
    for (int i = 1; i <= maxn - 5; i++) {
        is_prime[i] = 1;
    }
    int cnt = 0;
    is_prime[1] = 0;
    phi[1] = 1;
    for (int i = 2; i <= maxn - 5; i++) {
        if (is_prime[i]) {
            prime[++cnt] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= maxn - 5; j++) {
            is_prime[i * prime[j]] = 0;
            if (i % prime[j])
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            else {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    Euler();
    ll ans = 0;
    int last;
    for(int i = 1; i <= n; i++) {
        last = phi[i];
        for(int j = 1; j <= m; j++) {
            ans = (ans + last) % mod;
            last = last * i % mod;
        }
    }
    cout << ans << endl;
    return 0;
}