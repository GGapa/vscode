#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define int long long

int n, m;
int a[N], v[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
		cin >> a[i];
		if(i == 1) continue;
		int x = a[i], y = a[i-1];
        if(x == y) continue;
		if(y < x) swap(x,y);
		v[1] += abs(x - y);
		v[y] += abs(x-y); 
        v[x] -= abs(x-y);
		v[x] += abs(n-abs(x-y)); 
        v[y] -= abs(n-abs(x-y));
	}
    int ans = LLONG_MAX;
    for(int i = 1; i <= n; i++) {
        v[i] += v[i - 1];
        ans = min(ans, v[i]);
    }
    cout << ans << '\n';
    return 0;
}