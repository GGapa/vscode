#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
unordered_map<char, char> mp;

void solve() {
    int n; cin >> n;
    string A; cin >> A;
    A = " " + A;
    int cnt = 0;
    bool tag = true;
    auto tran = [&](int i) {
        A[i] = mp[A[i]];
    };
    while(A.size() > 1 && tag) {
        tag = false;
        rep(i, 1, A.size() - 1) if(A[i] == 'U') {
            tran(i - 1 == 0 ? A.size() - 1 : i - 1);
            tran(i + 1 >= A.size() ? 1 : i + 1);
            A.erase(i, 1);
            tag = true;
            cnt ^= 1;
            break;
        }
    }
    cout << (cnt ? "YES" : "NO") << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    mp['U'] = 'D';
    mp['D'] = 'U'; 
    while(T--) solve();
    return 0;
}