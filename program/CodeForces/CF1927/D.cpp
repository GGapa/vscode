#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

struct st {
    int l, r;
    int val;
};

void solve() {
    int n, cnt = 0, q;
    cin >> n;
    vector<int> a(n + 10), b(n + 10);
    vector<st> id(n + 10);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) {
        if(id[cnt].val != a[i]) {
            id[cnt].r = i - 1;
            id[++cnt].l = i;
            id[cnt].val = a[i];
        }
        b[i] = cnt;
    }
    cin >> q;
    if(id[cnt].r == 0) id[cnt].r = n;
    while(q--) {
        int l, r;
        cin >> l >> r;
        while(id[b[l]].val == id[b[r]].val && l < r && l <= n && r >= 1) {
            l = id[b[l]].r + 1;
            // r = id[b[r]].l - 1;
        }
        if(l > r) cout << "-1 -1\n";
        else cout << (id[b[l]].l < l ? id[b[l]].r : id[b[l]].l) << " " << (id[b[r]].r > r ? id[b[r]].l : id[b[r]].r) << '\n';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int  T; cin >> T;
    while(T--) solve();
    return 0;
}

/*
给定一个包含 n 个整数的数组 a 和 q 个查询。

每个查询由两个整数 l 和 r 表示（1≤l≤r≤n）。你的任务是找到每个查询的两个索引 i 和 j（或确定它们不存在），满足以下条件：

l≤i≤r；
l≤j≤r；
ai≠aj。
换句话说，对于每个查询，你需要在 al,al+1,…,ar 中找到一对不同的元素，或报告这样一对不存在。

输入
第一行输入一个整数 t（1≤t≤104） —— 测试用例数。接下来是每个测试用例的描述。

每个测试用例的第一行包含一个整数 n（2≤n≤2⋅105） —— 数组 a 的长度。

每个测试用例的第二行包含 n 个整数 a1,a2,…,an（1≤ai≤106） —— 数组 a 的元素。

每个测试用例的第三行包含一个整数 q（1≤q≤2⋅105） —— 查询的数量。

接下来的 q 行每行包含两个整数 l 和 r（1≤l<r≤n） —— 查询的边界。

保证在所有测试用例中 n 的值的总和不会超过 2⋅105。同样，保证在所有测试用例中 q 的值的总和不会超过 2⋅105。

输出
对于每个查询，输出两个用空格分隔的整数：i 和 j（l≤i,j≤r），其中 ai≠aj。如果不存在这样的一对，输出 i=−1 和 j=−1。

可以用空行分隔测试用例的输出。这不是强制性要求。
*/