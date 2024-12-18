/*
P9583 涂色
https://www.luogu.com.cn/problem/P9583
*/

#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;
typedef long long ll;

int n, m, q, k;
ll a[maxn], b[maxn], c[maxn], d[maxn];
ll ans1, ans2, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q >> k;
        while(q--) {
        int op, x;
        cin >> op >> x;
        if(op == 1) {
            a[x] = (a[x] + 1) % k;
        }
        if(op == 2) {
            b[x] = (b[x] + 1) % k;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(a[i] != 0) {
            ans1++;
            c[a[i]]++;
        }
    }
    for(int i = 1; i <= m; i++) {
        if(b[i] != 0) {
            ans2++;
            d[b[i]]++;
        }
    }
    ans = ans1 * m + ans2 * n - ans1 * ans2;
    for(int i = 1, j = k - 1; i <= k - 1, j >= 1; i++, j--) {
        ans -= c[i] * d[j];
    }
    cout << ans << endl;
    return 0;
}

/*
0 1 0 1
1 2 1 2
2 3 2 3

0 1 2
0 1 0 1

0 1 1
0 2 0 

*/