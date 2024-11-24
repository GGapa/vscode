//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1e5 + 5;


int A[N];
ll S[N], F[N];
int n;

ll work(ll mx) {
    list<int> q;  q.push_back(0);
    fill(F, F + 2 + n, 0); 
    for(int i = 1; i <= n + 1; i++) {
        for(; !q.empty() && S[i - 1] - S[q.front()] > mx; ) q.pop_front();
        F[i] = A[i] + F[q.front()];
        for(; !q.empty() && F[q.back()] >= F[i]; ) q.pop_back();
        q.push_back(i);
    }
    return  F[n + 1];
}

void solve() {
    cin >> n;
    fill(A, A + 2 + n, 0); fill(S, S + 2 + n, 0ll);
    rep(i ,1, n) cin >> A[i], S[i] = S[i - 1] + A[i];
    S[n + 1] = S[n];
    ll l = 1, r = S[n + 1], ans;
    while(l < r) {
        ll mid = (l + r) / 2;
        if(work(mid) <= mid) r = mid , ans = mid;
        else l = mid + 1;
    }
    // cout << ans << '\n';
    cout << l << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
考虑一个元素，若其算入最大值的贡献或者算入屏蔽带来的贡献是相同的。
但这样似乎并不能很好的处理
考虑进行二分
*/