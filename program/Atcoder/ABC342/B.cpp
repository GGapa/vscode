#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int n, q;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i], b[a[i]] = i;
    cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        if(b[l] < b[r]) cout << l << '\n';
        else cout << r << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;

    while(T--) 
        solve();

    return 0;
}

/*
问题描述
有N个人站成一排。站在第i个位置的人是第Pi号。

处理Q个查询。第i个查询如下：

给定整数Ai和Bi。在第Ai个人和第Bi个人之间，打印站在前面的人的人号。

约束
所有输入都是整数。

1 ≤ N ≤ 100
1 ≤ Pi ≤ N
Pi ≠ Pj（i ≠ j）
1 ≤ Q ≤ 100
1 ≤ Ai < Bi ≤ N
输入
输入以以下格式从标准输入给出：
*/