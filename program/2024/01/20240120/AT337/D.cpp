#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
typedef long long ll;
using namespace std;
const int maxn = 2e5 + 5;

int h, w, k;
string s[maxn];
vector<int> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> h >> w >> k;
	rep(i, 1, h) cin >> s[i];
	int ans = 2e9;
	rep(i, 1, h) {
		int o = 0, it = 0, cnt = 0;
		rep(j, 0, w - 1) {
			if(s[i][j] == 'x') {
				o = 0;			// o的个数 
				cnt = 0;		// 空闲的个数，用于累计ans 
				it = j;			// x的位置 
				continue;
			}
			cnt ++;
			o += (s[i][j] == 'o');		
			if(j - it>= k) o -= (s[i][j - k] == 'o');		// 超出距离的o不能做贡献要删去 
			if(cnt >= k)ans = min(ans, k - o);
		}
	}
	rep(j, 0, w - 1) {
		int o = 0, it = 0, cnt = 0;
		rep(i, 1, h) {
			if(s[i][j] == 'x') {
				o = 0;
				it = i;
				cnt = 0;
				continue;
			}
			cnt++;
			o += (s[i][j] == 'o');
			if(i - it >= k) o -= (s[i - k][j] == 'o');
			if(cnt >= k)ans = min(ans, k - o);
		}
	}
	ans = max(ans, 0);
	cout << (ans == 2e9 ? -1 : ans) << '\n';
	return 0;
}

