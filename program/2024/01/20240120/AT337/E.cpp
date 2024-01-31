#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
typedef long long ll;
using namespace std;

int n, len, num;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	len = (n - 1) / 2;
	num = (n + 1) / 2;
	cout << num << endl;
	rep(i, 1, num) {
		cout << len << " ";
		rep(j, i, i + len) cout << j << " \n"[j == i + len];
	}
	return 0;
}

