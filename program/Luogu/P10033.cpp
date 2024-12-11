#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;

int n;
int a[maxn], it[maxn];

void solve() {
    cin >> n;
    rep(i, 1, n) cin >> a[i], it[a[i]] = i;
    if(n == 2) cout <<"-1\n";
    else if(abs(it[2] - it[1]) == 1) {
        if(abs(it[3] - it[1]) == 1) {
            if(n == 3) rep(i, 1, n) cout << (a[i] == 3 ? 2 : 3) << " \n"[i == n];
            else rep(i, 1, n) cout << (a[i] == 1 ? 4 : (a[i] == 3 ? 2 : 1)) << " \n"[i == n];
        }
        else rep(i, 1, n) cout << (a[i] == 1 ? 3 : 1) << " \n"[i == n];
    }
    else rep(i, 1, n) cout << (a[i] == 1 ? 2 : 1) << " \n"[i == n];
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