// U318099 pay
// https://www.luogu.com.cn/problem/U318099?contestId=123900
#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
using namespace std;
const int maxn = 1e6 + 10;
#define int long long
int n, m;
int a[maxn];
int b[maxn];
long long f[maxn];
int Max = -1;
bool check() {
    for(int i = 1; i <= n; i++) {
        if(f[i] < a[i]) return false;
    }
    return true;
}
namespace LS {
    void Main() {
        for(int i = Max / 2; ; i++) {
        for(int j = 1;j <= m; j++) {
            bool flag = false;
            for(int q = max((long long)1, b[j] - i + 1); q <= min(n, b[j] + i - 1); q++) {
                f[q] += max(i - abs(b[j] - q), (long long)0);
                //if(f[q] < a[q]){break;}
            }
        }
        if(check()) {
            cout << i << endl;
            return;
        }
        for(int i = 1; i <= n; i++) f[i] = 0;
        }
    }
}
namespace N1 {
    void Main() {
        cout << a[1] << endl;
    }
}
namespace M1 {
    void Main() {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            a[i] += abs(i - b[1]);
            ans = max(ans, a[i]);
        }
        cout << ans << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        Max = max(Max, a[i]);
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    if(n == 1) {
        N1::Main();
        return 0;
    }   

    if(m == 1) {
        M1::Main();
        return 0;
    }

    LS::Main();
    
    return 0;
}