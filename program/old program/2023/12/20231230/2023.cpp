#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
#define int long long
const int maxn = 10;

int T;
int n, k, sum;
int a[maxn];


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    rep(_, 1, T) {
        cin >> n >> k;
        sum = 1;
        rep(i, 1, n) cin >> a[i], sum *= a[i];
        if(2023 % sum)  cout << "NO" << '\n';
        else {
            cout << "YES\n";
            rep(i, 2, k) cout << "1 ";
            cout << 2023 / sum << '\n';
        }
    }
    return 0;
}