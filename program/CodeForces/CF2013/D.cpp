#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<LL> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    if(n == 1) return cout << 0 << '\n', void();
    using AI = array<LL, 3> ;
    vector<AI> q(2 * n + 1);    //值和和。
    int head = 1, tail = 0;
    q[tail][0] = 1e18;
    per(i, n, 1) {
        if(A[i] < q[tail][0]) {
            q[tail + 1] = {A[i], q[tail][1] + A[i], q[tail][2] + 1};
            tail++;
            continue;
        }
        int l = head, r = tail, it = head;
        while(l <= r) {
            int mid = l + r >> 1;
            if(q[mid][0] <= (q[tail][1] - q[mid - 1][1] + A[i]) / (q[tail][2] - q[mid - 1][2] + 1)) it = mid, r = mid - 1;
            else l = mid + 1;
        }   //时间复杂度分析错了？其实这里并不需要二分，因为在队列里面根本不用放具体的值是多少，而且就算放了，也最多会产生 2n 个元素，且每个元素至多被 pop 一次。
        LL S = q[tail][1] - q[it - 1][1], cnt = q[tail][2] - q[it - 1][2];
        tail = it - 1; cnt++, S += A[i];
        if(S % cnt) {
            LL t1 = S / cnt + 1;
            tail++;
            LL nt = S % cnt;
            q[tail] = {t1, q[tail - 1][1] + nt * t1, q[tail - 1][2] + nt};
        }
        LL t1 = S / cnt; cnt -= S % cnt;
        tail++;
        q[tail] = {t1, q[tail - 1][1] + t1 * cnt, q[tail - 1][2] + cnt};
    }
    cout << q[head][0] - q[tail][0] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
1
5 
8 5 3 12 2
*/