#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int n, k, it = 1;
    cin >> n >> k;
    vector<int> a(n + 1);
    rep(i, 1, n) {
        if(a[i])  continue;
        int t = (n - i) / k + 1;
        if(i % 2) 
            for(int j = i, num = it; j <= n; j += k, num++) a[j] = num;
        else 
            for(int j = i, num = it + t - 1; j <= n; j += k, num--) a[j] = num;
        it = it + t;
    }
    rep(i, 1, n) cout << a[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

/*
你被给定两个整数 n 和 k（k≤n），其中 k 是偶数。

长度为 n 的排列是由 1 到 n 的 n 个不同整数组成的数组，其顺序任意。例如，[2,3,1,5,4] 是一个排列，但 [1,2,2] 不是一个排列（因为数组中的 2 出现两次），[0,1,2] 也不是一个排列（因为 n=3，但数组中没有 3）。

你的任务是构造一个长度为 n 的 k 级排列。

如果一个排列 p 被称为 k 级排列，当且仅当在所有长度为 k 的连续子段的和中（总共有 n−k+1 个），任意两个和之间的差别不超过 1。

更正式地说，要确定排列 p 是否为 k 级排列，首先构建一个长度为 n−k+1 的数组 s，其中 si=∑i+k−1j=ipj，即第 i 个元素等于子数组 pi,pi+1,…,pi+k−1 的和。

如果 max(s)−min(s)≤1，则称排列为 k 级排列。

找到任意长度为 n 的 k 级排列。

输入
第一行输入一个整数 t（1≤t≤104） —— 测试用例数。接下来是每个测试用例的描述。

每个测试用例的第一行包含两个整数 n 和 k（2≤k≤n≤2⋅105，k 是偶数），其中 n 是所需排列的长度。

保证所有测试用例中 n 的总和不超过 2⋅105。

输出
对于每个测试用例，输出长度为 n 的任意 k 级排列。

保证在给定约束条件下，总是存在这样的排列。
*/