//T364886 小粉兔的挂科与压力
//https://www.luogu.com.cn/problem/T364886?contestId=121028
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
const int maxn = 1e6 + 5;
typedef long long ll;
#define int long long
int n, c;
int a[maxn], Max[maxn];

signed main() {
    cin >> n >> c;
    Max[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        Max[i] = max(Max[i - 1], a[i]);
    }
    ll ansval = LLONG_MAX;
    int ansindex;
    for(int k = 0; k <= n; k++) {
        ll t = Max[k] + c * (n - k);
        if(t < ansval) {
            ansval = t;
            ansindex = k;
        }
    }
    cout << ansindex << " " << ansval << endl;
    return 0;
}