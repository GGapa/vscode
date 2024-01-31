#include <iostream>
#include <limits.h>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int d;
    cin >> d;
    int si = sqrt(d), ans = LLONG_MAX;
    for(int i = 1; i <= si; i++) {
        int t = sqrt(d - i * i);
        ans = min({ans, abs(i * i + t * t - d), abs(i * i + (t + 1) * (t + 1) - d), abs(i * i + (t - 1) * (t - 1) - d)});
        if(ans == 0) {
            ans = 0;
        }
    }
    cout << ans ;
    return 0;
}