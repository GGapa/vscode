#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<LL, siz>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k; cin >> n >> k;
    vector<AI<2>> A(n + 1);
    for(int i = 1, x, y; i <= n; i++) 
        cin >> x >> y, A[i][0] = x + y, A[i][1] = x - y;
    sort(A.begin() + 1, A.end());

    vector<LL> ans;
    auto check = [&](LL dis) {
        multiset<AI<2>> s;  // set 中 x 和 y 是反的。
        vector<LL>().swap(ans);
        for(int i = 1, j = 1; i <= n; i++) {
            for(; A[i][0] - A[j][0] > dis; j++) s.erase(s.find({A[j][1], A[j][0]}));
            for(auto it = s.lower_bound({A[i][1] - dis, (int)-2e9}); it != s.end() && (*it)[0] <= A[i][1] + dis; it++){
                ans.emplace_back(max(abs((*it)[0] - A[i][1]), abs((*it)[1] - A[i][0])));
                if(ans.size() > k) return true;
            }
            s.insert({A[i][1], A[i][0]});            
        }
        return false;
    };

    LL l = 1, r = 4e9, res = r;
    while(l <= r) {
        LL mid = l + r >> 1;
        if(check(mid)) r = mid - 1, res = mid;
        else l = mid + 1;
    }
    check(res - 1);
    sort(ans.begin(), ans.end());
    for(auto a : ans) cout << a << '\n';
    rep(i, (int)ans.size() + 1, k) cout << res << '\n';
    return 0;
}
/*

*/