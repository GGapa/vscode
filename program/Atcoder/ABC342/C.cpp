#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;


unordered_map<char, char> ans;



void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    for(char i = 'a'; i <= 'z'; i++) ans[i] = i;
    while(q--) {
        char l, r;
        cin >> l >> r;
        for(int i = 'a'; i <= 'z'; i++) if(ans[i] == l) ans[i] = r;
    }
    
    for(auto c : s) cout << ans[c];
    cout << '\n';
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
给定一个长度为N的字符串S，由小写英文字母组成。

你将对字符串S执行Q次操作。第i次操作（1≤i≤Q）由一对字符(ci,di)表示，对应以下操作：

将S中所有字符ci的出现替换为字符di。
在所有操作完成后，打印字符串S。

约束
1≤N≤2×10
5
S是一个由小写英文字母组成的长度为N的字符串。
1≤Q≤2×10
5
ci和di是小写英文字母（1≤i≤Q）。
N和Q是整数。
*/