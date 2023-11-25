//B3717 组合数问题
//https://www.luogu.com.cn/problem/B3717
#include <iostream>
using namespace std;
const int maxn = 5e6 + 5;
const int mod = 998244353;
#define ll long long 

ll T, N;
ll n, m;
ll inv[maxn], f[maxn];
ll Pow(ll a, ll b)
{
	ll ans = 1, base = a;
	while(b > 0)
    {
		if(b & 1)
			ans = ans * base % mod;
        base = base * base % mod;
		b >>= 1;
	}
	return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T >> N;
    f[0] = 1;
    for(int i = 1; i <= N; i++)
        f[i] = f[i - 1] * i % mod;
    inv[N] = Pow(f[N], mod - 2) % mod;
    for(int i = N - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
    ll ans = 0;
    while(T--) {
        cin >> n >> m;
        ans ^=  (f[n] * inv[m] % mod * inv[n - m] % mod);
    }
    cout << ans << endl;
    return 0;
}