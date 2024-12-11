#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

struct Number {
    int n = 0;
    vector<int> a;
    void update(int x) {
        int t = (a[x] & 1);
        a[x - 1] += (a[x] - t) >> 1;
        a[x] = t;
    }
    Number() : a(1){
        string s; cin >> s;
        for(auto c : s) {
            if(c == '1') a.push_back(0);
            if(c == '2') a.push_back(1);
            if(c == 'U') update(n), a.pop_back();
            if(c == 'L') a[n]--;
            if(c == 'R') a[n]++;
            n = (int) a.size() - 1;
        }
        per(i, n, 2) update(i);
        rep(i, 1, n) cout << a[i] << " \n"[i == n];
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Number A, B;
    int n = min(A.n, B.n), ans = INT_MAX, cha = 0;
    for(int i = 0; i <= n && abs(cha) <= 1e6; i++) {
        cha <<= 1; cha += A.a[i] - B.a[i];
        ans = min(ans, A.n + B.n - 2 * i + abs(cha));
    }
    cout << ans << '\n';
    return 0;
}