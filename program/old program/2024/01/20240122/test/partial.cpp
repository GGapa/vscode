#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

int n, q;
bool F1 = true, FI1 = true;

struct Node {
	int a, fa;
	int cnt1 = 0, cnt0 = 0;
}t[N]; 

vector<int> G[N];

namespace C1 {
	int ans = 0;
	void work(int x) {
		t[x].cnt1 = t[x].cnt0 = 0;
		for(auto to : G[x]) {
			t[x].cnt1 += (t[to].a == 1);
			t[x].cnt0 += (t[to].a == 0);
			work(to);
			t[x].cnt1 += t[to].cnt1;
			t[x].cnt0 += t[to].cnt0;
		}
	}
	void dfs(int x) {
		if(x > n) {
			work(1);
			int tmp = 0;
			rep(i, 1, n) 
				tmp += abs(t[i].a - 1) * t[i].cnt1;
			ans = max(ans, tmp);
			return ;
		}
		if(t[x].a != 2) 
			dfs(x + 1);
		else {
			t[x].a = 1;
			dfs(x + 1);
			t[x].a = 0;
			dfs(x + 1);
			t[x].a = 2;
		}
	}
	int main() {
		while(q--) {
			ans = 0;
			int id, type; char ch;
			cin >> id >> ch;
			t[id].a = (ch == '0' ? 0 : ch == '1' ? 1 : 2);
			dfs(1);
			cout << ans << '\n';
		}
		return 0;
	}
}

namespace C2 {
	int cnt1;
	void init() {
		rep(i, 1, n) {
			if(t[i].a == 2) t[i].a = 1;
			if(t[i].a == 1 && i != 1) cnt1++;
		}
	}
	int main() {
		init();
		while(q--) {
			int id, type;
			char ch;
			cin >> id >> ch;
			if(id != 1) {
				if(ch == '?' || ch == '1') type = 1;
				else type = 0;
				if(type != t[id].a) {
					cnt1 += (type == 1 ? 1 : -1);
					t[id].a = type;
				}
			}
			else {
				if(ch == '?' || ch == '0') type = 0;
				else type = 1;
				t[id].a = type;
			}
			cout << abs(t[1].a - 1) * cnt1 << '\n';
		}
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("partial.in", "r", stdin);
	freopen("partial.out", "w", stdout);
	cin >> n >> q;
	rep(i, 1, n) {
		char ch;
		cin >> ch;
		if(ch == '?') t[i].a = 2;
		else t[i].a = ch - '0';
	}
	for(int i = 2; i <= n; i++) {
		cin >> t[i].fa;
		G[t[i].fa].push_back(i);
		if(t[i].fa != 1) F1 = false;
		if(t[i].fa != i - 1) FI1 = false;
	}
	if(F1) {
		C2::main();
		return 0;
	}
	if(n <= 10) {
		C1::main();
		return 0;
	}
	return 0;
}
