//

#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long

void solve() {
    int n, q; cin >> n >> q;
    vector<int> c(n +1);
    vector<ll> s(n + 1), c1(n + 1);
    rep(i, 1, n) cin >> c[i], s[i] = s[i - 1] + c[i];
    rep(i, 1, n) c1[i] = c1[i - 1] + (c[i] == 1);
    while(q--) {
        int l, r; cin >> l >> r;
        ll sum = s[r] - s[l - 1], s1 = c1[r] - c1[l - 1], len = r - l + 1;
        // if(l == r || s1 > sum / 2) cout << "NO\n";
        if(s1 * 2 + len - s1 > sum || l == r)  cout << "NO\n";
        else cout << "YES\n";
    }
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
如果存在一个长度为 m 的数组 b，满足以下条件，那么长度为 m 的数组 a 被认为是好的：

∑i=1mai=∑i=1mbi；
对于从 1 到 m 的每个索引 i，ai≠bi；
对于从 1 到 m 的每个索引 i，bi>0。

给定一个长度为 n 的数组 c，其中每个元素大于 0。

你需要回答 q 个查询。在第 i 个查询中，你需要确定子数组 cl_i, cl_i+1, …, cr_i 是否好。

输入
第一行包含一个整数 t（1≤t≤104）— 测试用例的数量。

每个测试用例的第一行包含两个整数 n 和 q（1≤n,q≤3⋅105）— 数组 c 的长度和查询的数量。

每个测试用例的第二行包含 n 个整数 c1,c2,…,cn（1≤ci≤109）。

然后有 q 行跟随。第 i 行包含两个整数 li 和 ri（1≤li≤ri≤n）— 第 i 个子数组的边界。

输入的附加约束：所有测试用例中 n 的总和不超过 3⋅105；所有测试用例中 q 的总和不超过 3⋅105。

输出
对于每个查询，如果子数组是好的，则打印 YES。否则，打印 NO。

你可以以任何大小写形式输出答案中的每个字母（大写或小写）。例如，字符串 yEs、yes、Yes 和 YES 都将被识别为肯定的回答。

*/