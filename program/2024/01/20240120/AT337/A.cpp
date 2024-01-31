#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, sa, sb;
	cin >> n;
	sa = sb = 0;
	rep(i, 1, n) {
		int x, y;
		cin >> x >> y;
		sa += x; sb += y;
	}
	if(sa < sb) cout << "Takahashi\n";
	else if (sa == sb) cout << "Draw\n";
	else cout << "Aoki\n";
	return 0;
}

