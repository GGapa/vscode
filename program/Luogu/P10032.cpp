#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;

int T, n, m;
int a[maxn], cnt[maxn];

void work() {
    int res;
    memset(cnt, 0, sizeof(cnt));
    rep(i, 1, n) if(a[i] <= n) cnt[a[i]]++;
    per(i, n, 0) if(!cnt[i]) {res = i; continue;}
    rep(i, 1, n) if(a[i] > res || cnt[a[i]] > 1) a[i] = res;
}

void solve() {
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    work();
    if(m != 1) {
        work();
        if(m % 2) work();
    }
    rep(i, 1, n) cout << a[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while(T--) solve();

    return 0;
}