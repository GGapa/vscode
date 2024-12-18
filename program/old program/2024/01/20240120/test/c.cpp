#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
typedef long long ll;
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 3000 + 5;

int n, m, q;
string s, t;
int dp[maxn][maxn];

int so(string a, string b) {
	a.insert(0, " "); b.insert(0, " ");
	int la = a.length() - 1, lb = b.length() - 1;
	rep(i, 1, la) 
		rep(j, 1, lb) {
			dp[i][j] = 0;
			if(a[i] == b[j]) 
				dp[i][j] = dp[i-1][j-1] + 1; 
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			}
		}	
//	rep(i, 1, la) rep(j, 1, lb) cout << dp[i][j] << " \n"[j == lb];
	return dp[la][lb];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("c.in", "r", stdin);
	froepen("c.out", "w", stdout);
//	cout << so("baba", "bbaa") << endl;
	cin >> n >> m >> q;
	cin >> s >> t;
	while(q--) {
		int l1, l2, r1, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		string a = s.substr(l1 - 1, r1 - l1 + 1);
		string b = t.substr(l2 - 1, r2 - l2 + 1);
//		cout << a << " " << b << '\n';
		cout << so(a, b) << '\n';
	}

	return 0;
}


