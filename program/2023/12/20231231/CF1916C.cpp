#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;

int n;
ll sum, ji;

void solve() {
    sum = ji = 0;
    cin >> n;
    rep(i, 1, n) {
        int t;
        cin >> t;
        sum += t; ji += t % 2;
        if(i == 1) cout << sum << ' ';
        else cout << (sum - ji / 3 - (ji % 3 == 1)) << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}