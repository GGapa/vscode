#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

set<int> ans;
int a[N];
int n;

void solve() {
    cin >> n;
    ans.clear();
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        if(a[i] == a[i - 1] || a[i] == a[i - 2]) ans.insert(a[i]);
    }
    if(ans.size() == 0) {
        cout << -1 << '\n';
        return ;
    }
    int tot = 0;
    for(auto i : ans) {
        cout << i << (++tot == ans.size() ? '\n' : ' ');
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}