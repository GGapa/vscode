#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
typedef long long ll;
using namespace std;
const int maxn = 3e5 + 5;

int n, nxt[maxn];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int root;
	rep(i, 1, n) {
		int j;
		cin >> j;
		if(j == -1) {
			root = i;
			continue;
		}
		nxt[j] = i;
	}
	for(int i = root; i != 0; i = nxt[i]) {
		cout << i << " ";
	}
	
	
	return 0;
}

