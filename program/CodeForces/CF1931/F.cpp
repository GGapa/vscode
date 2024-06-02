#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;


void solve() {
    int n, k; cin >> n >> k;
    using VI = vector<int> ;
    vector<VI> A(k + 1, VI(n + 1));
    vector<int> in(n  +1);
    vector<multiset<int>> G(n + 1);
    rep(i,1 ,k) rep(j, 1, n) {
        cin >> A[i][j];
        if(j > 2) 
            G[A[i][j - 1]].insert(A[i][j]), in[A[i][j]]++;
    }
    queue<int>     q;
    rep(i, 1, n) if(!in[i]) q.push(i);
    for(int x; !q.empty(); ) {
        x = q.front(); q.pop();
        for(auto to : G[x]) {
            in[to]--;
            if(in[to] == 0) q.push(to);
        }
    }
    rep(i, 1, n) if(in[i]) {
        cout << "NO\n";
        return ;
    }
    cout << "YES\n";
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
有 n 人参加了编程竞赛聊天。聊天参与者按活动排序，但每个人都看到自己在列表顶部。

例如，聊天中有 4 个参与者，他们的顺序是 [2,3,1,4]。然后：

1 号用户看到的顺序是 [1,2,3,4]。
2 号用户看到的顺序是 [2,3,1,4]。
3 号用户看到的顺序是 [3,2,1,4]。
4 号用户看到的顺序是 [4,2,3,1]。
k 人在聊天中发布了截图，显示给这个用户的参与者顺序。这些截图是在短时间内拍摄的，并且参与者顺序没有改变。

你的任务是确定是否存在一种参与者顺序，可以得到所有 k 个截图。

输入
第一行包含一个整数 t（1≤t≤104）— 测试用例的数量。

接下来是每个测试用例的描述。

每个测试用例的第一行包含两个整数 n 和 k（1≤k≤n≤2⋅105，n⋅k≤2⋅105）— 聊天参与者的数量和发布截图的参与者数量。

接下来的 k 行包含由参与者发布的截图描述。

第 i 行包含 n 个整数 aij（1≤aij≤n，所有aij都是不同的）— 显示给参与者 ai0 的参与者顺序，其中 ai0 是截图的作者。可以证明在截图描述中，ai0 总是在列表顶部。

保证所有测试用例中 n*k 的总和不超过 2⋅105。同时保证所有截图作者都是不同的。

输出
对于每个测试用例，输出：

"YES"，如果存在至少一种参与者顺序，可以得到所有 k 个截图。
"NO"，否则。
*/