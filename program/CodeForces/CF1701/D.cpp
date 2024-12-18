#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<array<int, 3>> B(n + 1);
    rep(i, 1, n) {
        int x; cin >> x;
        if(x == 0) {
            B[i][0] = i + 1, B[i][1] = n, B[i][2] = i;
            continue;
        }
        B[i][2] = i;
        int l = 1, r = n, ans;
        while(l < r) {
            int mid = (l + r) >> 1;
            int t = i / mid;
            if(t <= x) r = mid;
            else l = mid + 1;
        }
        B[i][0] = l;
        l = 1, r = n;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            int t = i / mid;
            if(t < x) r = mid - 1;
            else l = mid;
        }
        B[i][1] = l;
    }
    using AI = array<int, 3>;
    sort(B.begin() + 1, B.end(), [&](const AI &x, const AI &y) {
        return x[0] < y[0];
    });
    vector<int> A(n + 1);
    priority_queue<AI, vector<AI>, greater<AI>> q;
    for(int i = 1, j = 1; i <= n || j <= n || q.size(); ) {
        while(i <= n && B[i][0] == j) q.push({B[i][1], B[i][0], B[i][2]}), i++;
        A[q.top()[2]] = j++, q.pop();
    }
    rep(i ,1, n) cout << A[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 22 0 6 1 1 0 3 0 15 1 0 0 1 3 0 0 0 0 0 0 1 0 0 7 1 0 0 0 3 3 1 0 7 1 1 1 2 1 1 1 3 2 0 0 3 1 0 1 7 1 2 6
0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 22 0 6 1 1 0 3 0 15 1 0 0 1 3 0 0 0 0 0 0 1 0 0 7 1 0 0 0 3 3 1 0 7 1 1 1 2 1 1 1 3 2 0 0 3 1 0 1 7 1 2 6
*/