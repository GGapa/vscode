//P1806 跑步
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int n;
ll f[505];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    f[0] = 1;
    rep(i, 1, n) {
         per(j, n, i) f[j] += f[j - i];   
    }
    cout << f[n] - 1<< '\n';
    return 0;
}
