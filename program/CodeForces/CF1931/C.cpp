#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 2);
    rep(i, 1, n) cin >> a[i];
    int l, r; l = 1, r = n;
    for(; l < n && a[l] == a[l + 1]; l++);
    for(; r > 1 && a[r] == a[r - 1]; r--);
    if(a[1] == a[n]) cout << max(r - l - 1, 0) << '\n';
    else cout << min(n - l, r - 1) << '\n';
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
你有一个包含 n 个整数的数组 a。

你最多只能执行一次以下操作：选择三个整数 i、j、x（1≤i≤j≤n），并将数组中索引从 i 到 j 的所有元素赋值为 x。此操作的价格取决于所选的索引，并等于 (j−i+1) 个 burles。

例如，数组等于 [1,2,3,4,5,1]。如果我们选择 i=2，j=4，x=8，那么应用此操作后，数组将变为 [1,8,8,8,5,1]。

使数组中所有元素相等，你需要花费的最少 burles 数量是多少？

输入
第一行包含一个整数 t（1≤t≤104）— 输入测试用例的数量。然后是每个测试用例的描述。

每个测试用例描述的第一行包含一个整数 n（1≤n≤2⋅105）— 数组的大小。

每个测试用例描述的第二行包含 n 个整数 a1，a2，…，an（1≤ai≤n）— 数组元素。

保证所有测试用例中 n 的总和不超过 2⋅105。

输出
对于每个测试用例，输出一个整数 — 使数组中所有元素相等需要花费的最少 burles 数量。可以证明这总是可以做到的。

*/