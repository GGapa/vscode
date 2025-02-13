#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int ret; cin >> ret;
    return ret;
}

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), cnt(n + 1);
    rep(i, 1, n) cin >> A[i], cnt[A[i]]++;
    int dis = 1;
    while(dis <= n && cnt[dis]) dis++;
    
    if(dis > n) {   // 说明全都出现过，此时判断 B
        int i1, in;
        rep(i, 1, n) {
            if(A[i] == 1) i1 = i;
            if(A[i] == n) in = i;
        }
        int t1 = ask(i1, in), t2 = ask(in, i1);
        if(t1 == 0 || t2 == 0) return cout << "! A" << endl, void();
        if(t1 < n - 1 || t2 < n - 1) return cout << "! A" << endl, void();
        return cout << "! B" << endl, void();
    }
    else {
        int t1 = ask(dis, 1 + (dis == 1)), t2 = ask(dis, 1 + (dis == 1));
        if(t1 && t2) return cout << "! B" << endl, void();
        return cout << "! A" << endl, void();
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
分两种情况讨论
如果又相同的和全都是不同的
又相同的那么必定有一个点没有出度
*/