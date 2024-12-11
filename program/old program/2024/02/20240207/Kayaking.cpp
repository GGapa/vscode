//  Kayaking CF863B
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 50 + 5;

int a[N << 1];
int n;

int work(int x, int y) {
    int it = 0, tp[3], sum = 0;
    rep(i, 1, n) {
        if(i == x || i == y) continue;
        tp[++it] = a[i];
        if(it == 2) {
            it = 0;
            sum += abs(tp[2] - tp[1]);
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1,  2 * n) cin >> a[i];
    n *= 2;
    sort(a + 1, a + 1 + n);
    int ans = INT_MAX  ;
    rep(i, 1, n) rep(j, i + 1, n) {
        ans = min(work(i, j), ans);
    }
    cout << ans << '\n';
    return 0;   
}