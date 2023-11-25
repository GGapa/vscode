// 费马小定理求解逆元 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, p;

ll qpow(ll x, ll y) {
	ll base = x, ans = 1;
	while(y > 0)  {
		if(y & 1) ans = (ans * base) % p;
		base = (base * base) % p;
		y >>= 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> p;
	for(int i = 1; i <= n; i++) {
		cout << qpow(i, p - 2) % p << "\n";
	}
	return 0;
}
