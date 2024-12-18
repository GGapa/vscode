#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

int n, m, d;
set<int> num;

void init() {
    rep(i, 2, 1e4 + 4) {
        bool tag = false;
        for(int t = 2; t * t <= i; t++) if(i % t == 0) {
            tag = 1;
            break;
        }
        if(tag) num.insert(i);
    }
}

void solve() {
    int len = m - n + 1;
    vector<int> A(len + 1);
    vector<int> use(m + 1);
    auto check = [&](int x) { 
        int sum = 0;
        rep(i, 1, d) {
            int t = x - (i - 1);
            if(t <= 0) break;
            sum += A[t];
            if(i >= 2 && !num.count(sum))  return false;
        } 
        return true;
    };
    bool tag = false;
    function<void(int)> dfs = [&](int x) {
        if(tag) return ;
        if(x > len) {
            // cout << x << endl;
            tag=  1;
            rep(i ,1, len) cout << A[i] << ",\n"[i == len];
            return ;
        } 
        rep(i, n, m) if(!use[i]) {
            use[i] = 1;
            A[x] = i;
            if(check(x)) dfs(x + 1);
            if(tag) return;
            use[i] = 0;
        }
    };
    dfs(1);
    if(!tag) cout << "No anti-prime sequence exists.\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    for(; cin >> n >> m >> d && n; ) solve();
    return 0;
}