#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> cnt(3), num[3];
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        num[x % 3].emplace_back(x);
        cnt[x % 3]++;
    }
    if((cnt[0] == 0 && cnt[1] != 0 && cnt[2] != 0) || cnt[0] > cnt[1] + cnt[2] + 1) return cout << "impossible\n", 0;
    // cout << "Yes\n";
    auto out = [&](int x) {
        cout << num[x].back() << " "; num[x].pop_back();
        cnt[x]--;
    };
    for(auto i : num[1]) {
        if(cnt[0] > 1) out(0);
        cout << i << " ";
    }
    if(cnt[0]) out(0);
    for(auto i : num[2]) {
        cout << i << " ";
        if(cnt[0]) out(0);
    }
    return 0;
}