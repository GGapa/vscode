/*
T356748 「Daily OI Round 1」Tree
https://www.luogu.com.cn/problem/T356748?contestId=123625
*/
#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;
typedef unsigned long long ll;
#define int ll
const int maxn = 1e5 + 5;

int n, d, k;
int T;
int dep[maxn], f[maxn], wait;
int sum = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> d >> k;
        memset(f, 0, sizeof(f));
        if(k == n - 1) {
            if(d > n) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 1; i < n; i++) {
            cout << 1 << " \n" [i == n - 1];
        }
        continue;
        }
        //sum = n * (n - 1) / 2;
        f[0] = 1;
        sum = 0;
        int if0len, usenode;
        for(int i = 1, tmp = 1; i <= maxn - 5 && tmp + f[i - 1] * k <= n; i++) {
            f[i] = f[i - 1] * k;
            sum += f[i] * i;
            if0len = i;
            tmp += f[i];
            usenode = tmp;
        }
        f[++if0len] = n - usenode;
        sum += f[if0len] * if0len;
        if(d > sum) {

            cout << "NO\n";
            continue;
        }
        int it = n - 1;
        for(int i = if0len; i >= 2 && sum > d; i--) {
            sum += f[i] * (i - 1);
            sum -= f[i] * i;
            f[i - 1] += f[i];
            f[i] = 0;
            it = i - 1;
        }
        f[it] -= (d - sum);
        f[it + 1]  += (d - sum);
        if(d < sum || f[it] < k) {
            cout << "NO\n";
            continue;
        }
        
        cout << "YES\n";
        for(int i = 1; i <= n - 1; i++) {
            for(int j = 1; j <= f[i]; j++) {
                cout << i << " ";
            }
        }
        cout << endl;

    }
    return 0;
}
/*
1 2 3 4
1 1 1 1     10
1 1 2 0     9
1 3 0 0     7
4 0 0 0     4
3 1 0 0     5
2 2 0 0     6
1 3 0 0     7
0 4 0 0     8

0 1 2 3 4
1 2 2 2 2   20
1 2 2 4 0   18
1 2 6 0 0   14

0 1 2 3 4
1 3 3 4 0

*/