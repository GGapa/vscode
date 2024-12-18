#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 5e5 + 5;

pair<int, int> F[N][2];
int lt[N], vis[N];
using PI = pair<int, int>;



signed main() {
    // int ST = clock();
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> s;
    for(int i = 1, x; i <= n; i++) {
        vector<pair<int, int>>(0).swap(s);
        cin >> x;
        if(lt[x]) {
            int it = lt[x] - 1;
            if(F[it][0].second != x) s.emplace_back(F[it][0].first + 2, x);
            else s.emplace_back(F[it][1].first + 2, x);
        }
        rep(j, 0, 1) s.push_back(F[i - 1][j]);
        sort(s.begin(), s.end(), greater<>());
        int cttt = 0;
        for(auto p : s) if(vis[p.second] != i && cttt < 2) {
            vis[p.second] = i;
            F[i][cttt] = p;
            cttt++;
            if(cttt == 2) break;
        }
        lt[x] = i;
    }
    cout << F[n][0].first << '\n';
    // cerr << (clock() - ST) * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}
/*
有一个朴素 DP F[i][j] 代表处理了前 1 - i，最后一个是 j 的最长序列。
但是发现第二维太浪费了，对于 1 - i 就只需要记录第一大和第二大的就足矣。
*/