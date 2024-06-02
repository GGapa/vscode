#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

struct Num {
    int num, del, len;
    bool operator<(const Num e) const {
        return del > e.del;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<Num> A(n + 1);
    rep(i, 1, n) {
        string s; cin >> s;
        A[i].del = A[i].len = 0;
        per(j, s.length() - 1, 0) {
            if(s[j] == '0') A[i].del++; //i -> j
            else break;
        }
        A[i].len = s.length();
    }
    sort(A.begin() + 1, A.end());
    int cnt = 0;
    rep(i, 1, n) 
        cnt += A[i].len - (i % 2 == 0 ? 0 : A[i].del);
    cout << (cnt > m ? "Sasha\n" : "Anna\n");
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
萨沙在情人节给安娜送了一个包含 n 个整数的列表。安娜不需要这个列表，所以她建议通过玩一个游戏来摧毁它。

玩家轮流进行。由于萨沙是绅士，所以他让安娜有权进行第一次移动。

在她的回合中，安娜必须选择列表中的一个元素 ai，并颠倒其数字的顺序。例如，如果安娜选择值为 42 的元素，它将变为 24；如果安娜选择值为 1580 的元素，它将变为 851。请注意，会移除前导零。在这样一次移动之后，列表中的元素数量不会改变。

在他的回合中，萨沙必须从列表中提取两个元素 ai 和 aj（i≠j），以任意顺序连接它们，然后将结果插入回列表中。例如，如果萨沙选择等于 2007 和 19 的元素，他将从列表中移除这两个元素，并添加整数 200719 或 192007。在这样一次移动之后，列表中的元素数量减少 1。

玩家不能跳过回合。游戏结束时，萨沙不能进行移动，即在安娜的移动后，列表中正好剩下一个数字。如果这个整数不小于 10^m（即，≥10^m），那么萨沙获胜。否则，安娜获胜。

可以证明游戏总是会结束。确定在两名玩家都采取最优策略的情况下谁会赢。

输入
第一行包含一个整数 t（1≤t≤104）— 测试用例的数量。

然后是测试用例的描述。

每个测试用例的第一行包含整数 n 和 m（1≤n≤2⋅105，0≤m≤2⋅106）— 列表中的整数数量和确定萨沙何时获胜的参数。

每个测试用例的第二行包含 n 个整数 a1，a2，…，an（1≤ai≤10^9）— 萨沙给安娜的列表。

保证所有测试用例中 n 的总和不超过 2⋅105。

输出
对于每个测试用例，输出：




"Sasha"，如果萨沙采取最优策略而获胜；
"Anna"，如果安娜采取最优策略而获胜。

*/