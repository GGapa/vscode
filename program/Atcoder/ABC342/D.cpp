#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> a(n), d;
    unordered_map<int, int> mp;
    for(auto & i : a) cin >> i;
    sort(a.begin(), a.end());
    int cnt = 0;
    int ans= 0 ;
    for(auto i : a) {
        ans += cnt;
        if(i == 0) {
            cnt++;
            continue;
        }
        for(int j = 2; j * j <= i; j++) while(i % (j * j) == 0) 
            i /= j * j;
        ans += mp[i];
        mp[i]++;
    }
    cout << ans << '\n';
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
Problem Statement
给定一个非负整数序列A=(A1,…,AN) ，长度为N。找到满足以下两个条件的整数对(i,j)的数量：

1≤i<j≤N
Ai Aj 是一个完全平方数。
这里，一个非负整数a被称为完全平方数，当它可以表示为a=d
2
，其中d是非负整数。

约束
所有输入都是整数。
2≤N≤2×10
5
0≤Ai≤2×10
5


*/