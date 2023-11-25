//P1972 [SDOI2009] HH的项链
//https://www.luogu.com.cn/problem/P1972
//2023-11-07 12:50
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;

int n, q;
int a[maxn], used[maxn], t[maxn], ans[maxn];
vector<pair<int, pair<int, int>>> que;//r l

int lowbit(int x) {
	return x & -x;
}

void add(int x, int y) {
	while(x <= n) {
		t[x] += y;
		x += lowbit(x);
	}
}

int query(int x) {
	int ans = 0;
	while(x > 0) {
		ans += t[x];
		x -= lowbit(x);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("AKIOI.in", "r", stdin);
//	freopen("AKIOI.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cin >> q;
	que.resize(q);
	int it = 0;
	for(auto& i : que) cin >> i.second.first >> i.first, i.second.second = it++;
	sort(que.begin(), que.end());
	it = 0;
	int tmp = 1;
	for(int i = 1; i <= n; i++) {
		if(used[a[i]]) add(used[a[i]], -1);
		add(i,1);
		used[a[i]] = i;
		while(i == que[it].first && !(it >= que.size())) {
			ans[que[it].second.second] = query(que[it].first) - query(que[it].second.first - 1);
			it++;
		}
		if(it >= que.size() || tmp >= que.size()) break;
	}
	for(int i = 0; i < q; i++) cout << ans[i] << "\n";

	return 0;
}
/*
编程语言
C++14 (GCC 9)
代码长度
1.24KB
用时
4.90s
内存
27.23MB
 GGapa

所属题目
P1972 [SDOI2009] HH的项链
评测状态
Accepted
评测分数
100
提交时间
2023-11-07 13:47:50
*/
