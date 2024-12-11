#include <bits/stdc++.h>;
using namespace std;
const int maxn = 1e5;
#define int long long

int n, t[maxn * 2], a[maxn], f[maxn];

int lowbit(int x) 
	{return x & (-x);}

void add(int x, int y){
	while(x <= n) {
		t[x] += y;
		x += lowbit(x);
	}
}

int find(int x) {
	int y = 0;
	while(x != 0) {
		y += t[x];
		x -= lowbit(x);
	}
	return y;
}

int fnd(int x) {
	if(x == f[x]) return x;
	return f[x] = fnd(f[x]);
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], add(i, a[i]), f[i] = i;
	f[n+1] = n + 1;
	int T;
	cin >> T;
	while(T--) {
		int op, x, y;
		cin >> op >> x >> y;
		if(x > y) swap(x, y);
		if(op == 1) {
			cout << find(y) - find(x - 1) << "\n";
		}
		else {
			for(int i = x; i <= y;) {
				int t = sqrt(a[i]);
				add(i,t - a[i]);
				a[i] = t;
				f[i] = (a[i] <= 1) ? i + 1 : i;
				i = (fnd(i) == i) ? i + 1 : f[i];
			}
		}
	}
	return 0;
}

/*
编程语言
C++14 (GCC 9)
代码长度
989B
用时
419ms
内存
3.45MB
 GGapa

所属题目
P4145 上帝造题的七分钟 2 / 花神游历各国
评测状态
Accepted
评测分数
100
提交时间
2023-10-18 20:10:52
*/