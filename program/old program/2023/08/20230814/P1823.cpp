/*
P1823 [COI2007] Patrik 音乐会的等待
https://www.luogu.com.cn/problem/P1823
*/

#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
int n;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    stack <pair<ll, ll> > watting; // First: 人数   Second: 升高
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll Input;
        cin >> Input;
        ll add = 1;
        for( ; !watting.empty() && Input >= watting.top().second; watting.pop()) {
            ans +=  watting.top().first;
            if(Input == watting.top().second) add += watting.top().first;
        }
        if(!watting.empty()) ans ++;
        watting.push(pair<ll, ll>(add, Input));
    }
    cout << ans << endl;
    return 0;
}
/*

2 4 1 2 2 5 1
STACK:
1 2

1 4
1 1

1 4
1 2
2 2

1 5
1 1


*/