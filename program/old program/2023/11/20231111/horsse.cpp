// http://124.221.194.184/contest/111/problem/230
// 0pts
#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000 + 5;

int n;
int ita, itb, ans; 
int a[maxn], b[maxn];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) cin >> b[i];
	sort(b + 1, b + 1 + n);
	ita = 1;
	while(a[ita] > b[itb] && itb <= n) itb++;
	ans -= itb - 1;
	while(a[ita] > b[itb] && itb <= n) itb++;
	while(ita <= n && itb <= n) {
		if(a[ita] < b[itb]) ans++;
		else if(a[ita] > b[itb]) ans--;
		ita++; itb++;
	}
	cout << ans << endl;
	return 0;
}

/*
3
92 83 71
95 87 74
*/
