#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    string s; cin >> s;
    unordered_map<char, int> mp;
    int n = s.size();
    int it = 0;
    rep(i, 0, n - 2) {
        if(s[i] != s[i + 1])    it = i;
    }
    if(it != 0 && s[n - 1] != s[0]) it = n - 1;
    cout << it + 1 << '\n';
    
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
分：150分

问题描述
给定一个由小写英文字母组成的字符串S。字符串S的长度在3到100之间，包括3和100。

除了S中的一个字符外，所有字符都相同。

找到x，使得S的第x个字符与所有其他字符都不同。

约束
S是一个长度在3到100之间的字符串，由两个不同的小写英文字母组成。
除了S中的一个字符外，所有字符都相同。
输入
输入以以下格式从标准输入给出：
*/