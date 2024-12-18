#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    auto a1 = [&](int i) { 
        char c;
        cout << "? 1 " << i << endl; 
        cin >> c;
        return c;
    };
    auto a2 = [&](int i, int j) {
        int ret ;
        cout << "? 2 " << i << " " << j << endl;
        cin >> ret;
        return ret;
    };
    int cnt = 0;
    vector<int> A(n + 1), lt;
    rep(i, 1, n) {
        vector<int> id(cnt);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](const int &x, const int &y) {
            return lt[x] > lt[y];
        });
        int l = 0, r = cnt, rt;
        while(l < r) {
            int mid = l + r >> 1;
            int t = a2(lt[id[mid]], i);
            if(t == mid + 1) r = mid;
            else l = mid + 1;
        }
        rt = l;
        if(rt == cnt) A[i] = cnt++, lt.push_back(i);
        else A[i] = id[rt], lt[A[i]] = i;
    }
    string ans, t;
    rep(i, 0, cnt - 1) {
        char c = a1(lt[i]);
        t += c;
    }
    rep(i, 1, n) ans += t[A[i]];
    cout << "! ";
    cout << ans << endl;
    return 0;
}