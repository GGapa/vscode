#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m, n; cin >> m >> n;
    ll ans = 0, sum = 0;
    vector<int> A(n + 1);
    priority_queue<int, VI, greater<int>> q;
    rep(i, 1, n) cin >> A[i], sum += A[i], q.push(A[i]);
    int cnt = 0;
    while(!q.empty() && sum > m) {
        cnt++;
        sum -= (int)q.size();
        while(!q.empty() && q.top() == cnt) {
            q.pop(); ans += cnt * cnt;
        }
    }
    cout << ans + ((int)q.size() + sum - m) * cnt * cnt + (m - sum) * (cnt - 1) * (cnt - 1) << '\n';
    return 0;
}
/*
9 4
4
5
2
3
*/