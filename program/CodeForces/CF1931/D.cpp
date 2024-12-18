#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int n, x, y; 
    n = 2e5, x = rand(), y = rand();
    cin >> n >> x >> y;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    // rep(i, 1, n) A[i] = rand();
    ll ans = 0;
    map<int, vector<int>> x1;
    map<int, map<int, int>> y1;
    rep(i, 1, n) {
        int & a = A[i];
        int mx = a % x, my = a % y;
        // for(auto j : x1[(x - mx) % x]) if(j % y == a % y) 
        //     ans++;
        ans += y1[(x - mx) % x][a % y];
        // x1[mx].push_back(a);
        y1[mx][a % y]++;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >>  T;
    while(T--) solve();
    return 0;
}
/*
波利卡普有两个喜欢的整数 x 和 y（它们可以相等），他找到了一个长度为 n 的数组 a。

波利卡普认为一对索引 ⟨i,j⟩（1≤i<j≤n） 是美丽的，如果：

ai+aj
 可以被 x 整除；
ai−aj
 可以被 y 整除。

例如，如果 x=5，y=2，n=6，a=[1,2,7,4,9,6]，那么唯一的美丽对是：

⟨1,5⟩：a1+a5=1+9=10（10 可以被 5 整除），a1−a5=1−9=−8（−8 可以被 2 整除）；
⟨4,6⟩：a4+a6=4+6=10（10 可以被 5 整除），a4−a6=4−6=−2（−2 可以被 2 整除）。

找出数组 a 中美丽对的数量。

输入
第一行输入一个整数 t（1≤t≤104） — 测试用例的数量。接下来是每个测试用例的描述。

每个测试用例的第一行包含三个整数 n、x 和 y（2≤n≤2⋅105，1≤x,y≤109） — 数组的大小和波利卡普喜欢的整数。

每个测试用例的第二行包含 n 个整数 a1，a2，…，an（1≤ai≤109） — 数组的元素。

保证所有测试用例中 n 的总和不超过 2⋅105。

输出
对于每个测试用例，输出一个整数 — 数组 a 中美丽对的数量。
*/