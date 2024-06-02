// Moving Chips
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int cnt1 = 0, cnt2 = 0, ans = 0;
    rep(i, 1, n) {
        if(a[i] == 0) cnt1++;
        if(a[i] == 1) {
            if(cnt2) 
                ans += cnt1;
            cnt1 = 0;
            cnt2 = 1;
        }
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--)  solve();
    return 0;
}

/*
有一条带有 n 个单元的缎带，从左到右编号为 1 到 n。每个单元要么包含一个芯片，要么是空闲的。

您可以执行以下操作任意次数（可能为零）：选择一个芯片并将其移动到最靠左的空闲单元。您可以选择任何芯片，只要它左边至少有一个空闲单元。移动芯片时，操作前的单元变为空闲。

您的目标是以这样的方式移动芯片，使它们形成一个单一的块，其中没有空闲单元。您需要执行的最小操作次数是多少？

输入
第一行包含一个整数 t（1≤t≤1000）— 测试用例的数量。

每个测试用例包括两行：

第一行包含一个整数 n（2≤n≤50）— 单元的数量；
第二行包含 n 个整数 a1,a2,…,an（0≤ai≤1）；ai=0 表示第 i 个单元为空闲；ai=1 表示第 i 个单元包含一个芯片。
输入的附加约束：在每个测试用例中，至少有一个单元包含芯片。

输出
对于每个测试用例，打印一个整数 — 您需要执行的最小操作次数，以便所有芯片形成一个没有空闲单元的单一块。

*/