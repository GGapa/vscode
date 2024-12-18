#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    sort(A.begin() + 1, A.end());
    int mn = A[1], dis = 1;
    for(int i = 1; i < n; i++) {
        if((A[i + 1] - A[i]) * i <= k) {
            k -= (A[i + 1] - A[i]) * i;
            mn = A[i + 1];
            dis = i + 1;
        }
        else break;
    }
    mn += (k / dis); k %= dis;
    dis -= k;
    cout << (mn * n) + (n - dis) - n + 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

/*
你有一些卡片。每张卡片上都写有 1 到 n 之间的整数：具体地，对于每个 i 从 1 到 n，你有 ai 张卡片，上面写有数字 i。

商店中也有每种类型的卡片的无限量库存。你有 k 枚硬币，因此你总共可以购买 k 张新卡片，而你购买的卡片上的数字可以是 1 到 n 之间的任意整数。

购买新卡片后，你将所有卡片重新排成一行。重新排列的得分是长度为 n 的（连续的）子数组，这些子数组是 [1,2,…,n] 的一个排列。你能获得的最大得分是多少？

每个测试包含多个测试用例。第一行包含测试用例数 t (1≤t≤100)。接下来是每个测试用例的描述。

每个测试用例的第一行包含两个整数 n、k (1≤n≤2⋅105, 0≤k≤1012) — 卡片的不同类型数和硬币数。

每个测试用例的第二行包含 n 个整数 a1,a2,…,an (1≤ai≤1012) — 你一开始拥有的类型 i 的卡片数。

保证所有测试用例中 n 的总和不超过 5×105。
*/