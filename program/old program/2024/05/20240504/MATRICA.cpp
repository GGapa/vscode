// MATRICA
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long LL;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> cnt(30), tmp(30);
    int ji = 0;
	priority_queue<int, VI, greater<int>> q; 
	
	int n, k; cin >> n >> k;
	vector<int> s(n + 1);
	
	rep(i, 1, k) {
		char c; cin >> c;
		cin >> cnt[c - 'A'];
		tmp[c - 'A'] = cnt[c - 'A'];
		if(cnt[c - 'A'] % 2) {
			q.push(c - 'A'), ji++, cnt[c - 'A']--;
		}
		cnt[c - 'A'] /= 2;
	}
//	rep(i, 0, 25) cout << cnt[i] << " " ;
//	cout << endl;
	if(ji > n || (n - ji) % 2) return cout << "IMPOSSIBLE", 0;
	int it = 0;
	while(!cnt[it]) it++;
	rep(i, 1, n) {
		if(!ji) s[i] = it, q.push(it), ji++, cnt[it]--;
		else {
			int c = q.top();
			if(it < c && n - i + 1 > ji) cnt[it]--, s[i] = it, q.push(it), ji++;
			else s[i] = c, q.pop(), ji--; 
		}
		// cout << it << "\n";
		int t = n - i;
		while(cnt[it] <= t && it <= 25) t -= cnt[it++];
		cnt[it] -= t;
	}
	
	int p; cin >> p;
	vector<int> out(p + 1);
	rep(i, 1, p) cin >> out[i];
	
	rep(i, 1, n) tmp[s[i]]--;
    rep(i, 0, 25) tmp[i] /= 2;
    rep(i, 1, 25) tmp[i] += tmp[i - 1];

	// rep(i, 0, 25) cout << tmp[i] << '\n';

	auto print = [&](int i, int j) {
		if(i > j) swap(i, j);
		if(i == j) return cout << char('A' + s[i]), void();
		int ls = (2 * n - i) * (i - 1) / 2 + j - i;
		// cout << ls << '\n';
		int ch = lower_bound(tmp.begin() , tmp.begin() + 25, ls) - tmp.begin();
		cout << char('A' + ch);
	};
	rep(i, 1, n)  {
		rep(j, 1, p) print(i, out[j]);
		cout << '\n';
	}
    return 0;
}
/*
50 7
A 274
B 265
E 308
K 289
O 543
T 285
Z 536
50
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 
*/