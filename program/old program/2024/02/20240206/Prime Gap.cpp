#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 100000 + 5;

int n;
vector<int> pri;
bool vis[1299709 + 5];

void init() {
    rep(i, 2, 1299709) {
        if(!vis[i]) pri.push_back(i);
        int len = pri.size();
        for(int j = 0, t; j < len && (t = pri[j] * i) <= 1299709; j++) {
            vis[t] = true;
            if(i % pri[j] == 0) continue;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    while(1) {
        cin >> n; if(n == 0) break;
        if(!vis[n]) {
            cout << 0 << '\n';
            continue;
        }
        int i = lower_bound(pri.begin(), pri.end(), n) - pri.begin();
        cout << pri[i] - pri[i - 1] << '\n';
    }
    return 0;
}