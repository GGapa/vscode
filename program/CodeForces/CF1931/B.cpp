#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for(auto & i : a) cin >> i, sum += i;
    int av = sum / n;
    ll cnt1, cnt2; cnt1 = cnt2 = 0;
    for(auto i : a) {
        // if(i >= av) cnt1 += i - av;
        // else cnt1 += i - av;
        cnt1 += i - av;
        if(cnt1 < 0) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
    return ;
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
有 n 个水容器排列在一起，编号从 1 到 n。每个容器可以容纳任意数量的水；最初，第 i 个容器包含 ai 单位的水。ai 的总和是 n 的倍数。

您可以任意次数地应用以下操作：从第 i 个容器向第 j 个容器倾倒任意数量的水，其中 i 必须小于 j（即 i<j）。任何索引都可以任意次数选择为 i 或 j。

确定是否可以使用这个操作使所有容器中的水量相同。

输入
输入的第一行包含一个整数 t（1≤t≤104）— 测试用例的数量。然后是测试用例的描述。

每个测试用例的第一行包含一个整数 n（1≤n≤2⋅105）— 带有水的容器数量。

每个测试用例的第二行包含 n 个整数 a1，a2，…，an（0≤ai≤109）— 容器中的水量。保证每个测试用例中 ai 的总和不超过 2⋅109。同时，ai 的总和是 n 的倍数。

保证输入中所有测试用例的 n 总和不超过 2⋅105。

输出
输出 t 行，每行是相应测试用例的答案。作为答案，如果可以使用上述操作使所有容器中的水量相同，请输出 "YES"。否则，输出 "NO"。

您可以以任何大小写形式输出每个字母（小写或大写）。例如，字符串 "yEs"，"yes"，"Yes" 和 "YES" 都将被接受为积极的答案。
*/