//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

int pri[] = {0, 3, 11, 101, 1009, 10007, 100003, 1000003, 10000019, 100000007};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) {
        int a, b; cin >> a >> b; 
        cout << __gcd(a, b) << '\n';
    }

    return 0;
}
/*
9
200000014 200000016
110000209 110000220
101000303 101000404
100903027 100904036
100140049 100150056
100903027 101003030
101000303 102000306
110000209 120000228
200000014 300000021
*/
