#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;



void solve() {
    int n; string ans;
    cin >> n;
    vector<int> a(n), cnt(27);
    for(auto& i : a) cin >> i;
    for(auto i : a) {
        rep(j, 0, 25) if(cnt[j] == i) {
            cnt[j]++; 
            ans += (char)(j + 'a');
            break;
        }
    }
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

