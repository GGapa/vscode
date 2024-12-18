#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> A(7);
    rep(i, 1, 6) cin >> A[i];
    int n; cin >> n;
    vector<int> B(n + 1);
    rep(i, 1, n) cin >> B[i];
    vector<array<int, 2>> num;
    rep(i, 1, n) rep(j, 1, 6) num.push_back({B[i] - A[j], i});
    sort(num.begin(), num.end());
    list<array<int, 2>> q;
    int cnt = 0;
    vector<int> F(n + 1);
    LL ans = LLONG_MAX;
    rep(i, 0, (int)num.size() - 1)  {
        q.push_back(num[i]); 
        if(F[num[i][1]] == 0) cnt++;
        F[num[i][1]]++;
        while(!q.empty() && F[q.front()[1]] > 1) F[q.front()[1]]--, q.pop_front();
        if(cnt >= n) 
            ans = min(ans, q.back()[0] - q.front()[0]) ;
    }
    cout << ans << '\n';
    return 0;
}