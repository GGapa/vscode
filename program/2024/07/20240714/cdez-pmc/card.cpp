#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

ll n;

void baoli() {
	ll t = 2, tt = 2;
	ll ans = 1;
	ll m = n * 2;
	while(t != m - 2 && t != 1) {
		t *= 2; tt *= 2;
		if(t >= m) t -= m, t += 1;
		ans++;
		cout << t << '\n';
	}
	cout << ans * (1 + (t != 1))  << '\n';
	cout << tt << '\n';
	cout << "---------\n";
}

void solve() {
	cin >> n;
//	baoli();
	ll t = 2;
	ll ans = 1;
	ll m = n * 2;
	while(t != m - 2 && t != 1) {
		ll tmp  = __lg(m / t) ;
		t = t * pow(2ll, tmp + 1);
		if(t >= m) t %= m, t += 1;
		ans += tmp + 1;	
	}
	cout << ans * (1 + (t != 1)) - 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
	int T ;cin >> T;
	while(T--) solve();
	
    return 0;
}
/*
1 2 3 4 5 6 7 8 9 10
1 6 2 7 3 8 4 9 5 10
1 8 6 4 2 9 7 5 3 10

1 2 3 4 5 6 7 8
1 5 2 6 3 7 4 8
1 3 5 7 2 4 6 8

 
*/
