// P2168 [NOI2015] 荷马史诗 
//https://www.luogu.com.cn/problem/P2168
// 2023-11-12 14:50 NOI Linux

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

ll n, k, ans = 0;

priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;


int main() {
    // freopen("AKioi.in", "r", stdin);
    // freopen("AKioi.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        ll tmp;
        cin >> tmp;
        q.push(make_pair(tmp, 1));
    }
    while((q.size() - 1) % (k - 1) != 0) q.push(make_pair(0, 1));
    while(q.size() >= k ) {
        ll h = -1, w = 0;
        for(int i = 1; i <= k; i++) {
            auto t = q.top(); q.pop();
            h = max(t.second, h);
            w += t.first;
        }
        ans += w;
        q.push(make_pair(w, h + 1));
    }
    cout << ans << '\n' << q.top().second - 1 << '\n';
    return 0;
}

/*
编程语言
C++14 (GCC 9)
代码长度
1011B
用时
1.67s
内存
2.59MB
 GGapa

所属题目
P2168 [NOI2015] 荷马史诗
评测状态
Accepted
评测分数
100
提交时间
2023-11-12 15:13:30
*/