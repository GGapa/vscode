//T363241 Collatz 猜想
//https://www.luogu.com.cn/problem/T363241?contestId=123906

#include <iostream>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    int ans = 0;
    int S = min(n, (long long)10000000);

    for (int i = 1; i <= S; i++) {
        int x = i, sum = 0;
        while (x != 1) {
            sum++;
            x = x % 2 == 0 ?(x >> 1): x * 3 + 1;
            if (sum > k) {
                ans++;
                break;
        }
        }
        
    }

    int x = 1 << 23, sum = 0, p = 23;
    while (x <= n && p <= k) {
        sum++;
        x *= 2;
        p++;
    }

    ans += max((n >= 10000000 ? n - 10000000 : 0) - sum, 0LL);
    cout << ans << endl;
    return 0;
}
