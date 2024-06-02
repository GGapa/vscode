// D
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> m >> n;
    using AI = array<int, 2>;
    unordered_map<int, int> mp;
    vector<int> a(m + 1);
    mp[0] = m;
    rep(i, 1, n) {
        int x, y; cin >> x >> y;
        mp[a[x]]--; 
        if(mp[a[x]] <= 0) mp.erase(a[x]);
        a[x] += y;
        mp[a[x]]++;
        cout << mp.size() << '\n';
    }
    return 0;
}

/*

问题陈述：
高桥正在主持一场有 N 名选手的比赛，编号从 1 到 N。这些选手将竞争得分。目前，所有选手的分数都是零。

高桥的先知能力让他知道选手的得分将如何改变。具体来说，对于 i=1,2,…,T，玩家 A_i 的得分将在 i 秒后增加 B_i 分。得分不会有其他变化。

高桥喜欢得分的多样性，他想知道每个时刻在选手的得分中会出现多少个不同的得分值。对于每个 i=1,2,…,T，找出 i+0.5 秒后在选手的得分中有多少个不同的得分值。

例如，如果某一时刻玩家的得分是 10、20、30 和 20，那么在那一时刻，玩家的得分中有三个不同的得分值。
*/