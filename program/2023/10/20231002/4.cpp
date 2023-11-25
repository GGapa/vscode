#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e6 + 5;
typedef long long ll;
typedef unsigned long long ull;

int n;
ll h[maxn], w[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ll sumw = 0;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> h[i] >> w[i];
    }

    for(int i = 1; i <= n; i++) {
        ll lw = w[i];
        int it = i + 1;
        while(h[i] <= h[it]) {
            if(lw > h[i]) break;
            lw += w[it];
            it++;
        }
        ans = max(ans, (ll)min(h[i], lw) * min(h[i], lw));
    }
    cout << ans << endl;
    return 0;

}