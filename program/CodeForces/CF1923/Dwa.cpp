// D
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long

// struct Node {
//     ll cnt, val, it;
// }

void solve() {
    int n; cin >> n;
    // stack<Node> s;
    vector<int> a(n + 1), ans(n + 1, 1e9), cn(n + 1);
    vector<ll> s(n + 1);
    rep(i, 1, n) cin >> a[i], s[i] = s[i - 1] + a[i];
    // ll sum = 0;
    rep(i, 1, n) {
        if(a[i - 1] > a[i]) ans[i] = 1, cn[i] = a[i - 1] + a[i];
        else {
            int sum = 0, st =0, tag = 0;
            for(int j = i - 1; j >= 1 && sum <= a[i]; ) {
                if(ans[j] == 1e9) {
                    if(a[j] <= a[j + 1] || a[j] <= sum) {
                        sum = 0;
                        st = 0;
                        break;
                    }
                    sum += a[j];
                    st++;
                    j--;
                }
                else if(sum + a[j] > a[i]) {
                    st++;
                    sum += a[j];
                    break;
                }
                else {
                    tag = 1;
                    sum += cn[j];
                    st += ans[j];
                    j -= ans[j] + 1;
                }
            }
            if(sum > a[i]) {
                ans[i] = st + tag;
                cn[i] = sum + a[i];
            }
        }
    }
    auto tmp = ans;
    fill(ans.begin(), ans.end(), 1e9);
    cn.clear();
    per(i, n - 1, 1) {
        if(a[i + 1] > a[i]) ans[i] = 1, cn[i] = a[i + 1] + a[i];
        else {
            int sum = 0, st =0, tag = 0;
            for(int j = i + 1; j <= n && sum <= a[i]; ) {
                if(ans[j] == 1e9) {
                    if(a[j] <= a[j - 1] || a[j] <= sum) {
                        sum = 0;
                        st = 0;
                        break;
                    }
                    sum += a[j];
                    st++;
                    j--;
                }
                else if(sum + a[j] > a[i]) {
                    st++;
                    sum += a[j];
                    break;
                }
                else {
                    tag = 1;
                    sum += cn[j];
                    st += ans[j];
                    j -= ans[j] + 1;
                }
            }
            if(sum > a[i]) {
                ans[i] = st + tag;
                cn[i] = sum + a[i];
            }
        }
    }
    rep(i, 1, n) cout << (min(ans[i], tmp[i]) == 1e9 ? -1 : min(ans[i], tmp[i])) << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
// 本题死因，没有想到二分。



/*
在一条直线上放置了 n 只黏液生物。这些生物从左到右按顺序编号为 1 到 n。第 i 只黏液生物的大小是 ai。

每一秒钟，会发生以下事件：恰好一只黏液生物吞噬其相邻的一只生物，并将其大小增加为被吞噬生物的大小。一只黏液生物只能吞噬其严格比其相邻生物大的生物。如果没有黏液生物严格比其相邻生物大，过程就结束了。

例如，假设 n=5，a=[2,2,3,1,4]。过程可以进行如下：

首先，第3只黏液生物吞噬第2只黏液生物。第3只黏液生物的大小变为5，第2只黏液生物被吞噬。
然后，第3只黏液生物吞噬第1只黏液生物（它们是相邻的，因为第2只黏液生物已被吞噬）。第3只黏液生物的大小变为7，第1只黏液生物被吞噬。
然后，第5只黏液生物吞噬第4只黏液生物。第5只黏液生物的大小变为5，第4只黏液生物被吞噬。
然后，第3只黏液生物吞噬第5只黏液生物（它们是相邻的，因为第4只黏液生物已被吞噬）。第3只黏液生物的大小变为12，第5只黏液生物被吞噬。
对于每只黏液生物，计算其被另一只黏液生物吞噬所需的最小秒数（在过程可能进行的所有方式中），或报告这是不可能的。

输入
第一行包含一个整数 t（1≤t≤104）— 测试用例的数量。

每个测试用例的第一行包含一个整数 n（1≤n≤3⋅105）— 黏液生物的数量。

每个测试用例的第二行包含 n 个整数 a1,a2,…,an（1≤ai≤109）。

所有测试用例中 n 的总和不超过 3⋅105。

输出
对于每个测试用例，打印 n 个整数。第 i 个整数应等于第 i 只黏液生物被另一只黏液生物吞噬所需的最小秒数，如果不可能则为 -1。

4 2 3 6 1 1 8 

*/