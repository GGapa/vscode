#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n, a[maxn], b[maxn], mp[maxn], f[maxn];
int len;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], mp[a[i]] = i;
	for(int i = 1; i <= n; i++) cin >> b[i], f[i] = INT_MAX;
	f[0] = 0;
	for(int i = 1; i <= n; i++) {
		int l = 0, r = len, mid;
		if(mp[b[i]] > f[len]) f[++len] = mp[b[i]];
		else {
			while(l < r) {
				mid = (l + r) >> 1;
				if(f[mid] > mp[b[i]]) r = mid;
				else l = mid + 1;
			}
			f[l] = min(mp[b[i]], f[l]);
		}
	}
	cout << len << "\n";
	return 0;
}

/*
编程语言
C++14 (GCC 9)
代码长度
648B
用时
91ms
内存
1.98MB
 GGapa

所属题目
P1439 【模板】最长公共子序列
评测状态
Accepted
评测分数
100
提交时间
2023-10-18 19:17:00
*/