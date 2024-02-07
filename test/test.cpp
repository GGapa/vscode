#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5; 


int n, k;
int dp[maxn][maxn];

struct Node {
	int x, y;
}a[maxn];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)  
		cin >> a[i].x >> a[i].y;

	sort(a + 1, a + 1 + n, [](const Node& x, const Node &y) {
        if(x.x == y.x) return x.y < y.y;
	    return x.x < y.x;
    });
	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		dp[i][k] = 1;
		for(int j = 0; j <= k; j++) {
			for(int q = 1; q < i; q++) {
				if(a[q].x > a[i].x || a[q].y > a[i].y) continue;
				int dx = abs(a[i].x - a[q].x);
				int dy = abs(a[i].y - a[q].y);
				int d = dx + dy - 1;
				if(j + d > k) continue;
                dp[i][j] = max(dp[i][j], dp[q][j + d] + d + 1);
				ans = max(ans, dp[i][j] + j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}