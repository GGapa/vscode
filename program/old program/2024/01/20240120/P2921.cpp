#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
typedef long long ll;
using namespace std;
const int maxn = 100000 + 5;
int n;
int a[maxn], dfn[maxn], belong[maxn], minc[maxn], sudfn[maxn];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("P2921.in", "r", stdin);
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	rep(x, 1, n) {
		for(int i = x, cnt = 0; ; i = a[i], cnt++) {
			if(belong[i] == 0) {
				belong[i] = x;
				dfn[i] = cnt;
				continue;
			}
			if(belong[i] == x) {
				minc[x] = cnt - dfn[i];
				sudfn[x] = dfn[i];
				cout << cnt << '\n';
				break;
			}
			minc[x]  = minc[belong[i]];
			sudfn[x] = cnt + max(sudfn[belong[i]] - dfn[i], 0);
			cout << sudfn[x] + minc[x] << '\n';
			break;
		}
	}
	return 0;
}

