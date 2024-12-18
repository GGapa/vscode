/*
几乎是素数(Almost Prime Numbers, UVa10539)
https://www.luogu.com.cn/problem/UVA10539
*/
#include <iostream> 
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

typedef unsigned long long ull;
const int maxn = 1000010;
bitset<maxn> vis;
int p[maxn];
vector<int> inv;
int cnt;

void GetPrime() {
    for (int i = 2; i <= maxn; i++) {
        if (!vis[i]) p[cnt++] = i;
        for (int j = 0; j < cnt and p[j] * i <maxn; j++) {
            vis[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    GetPrime();
    int T;
    cin >> T;
    int l, r;
    while(T--) {
        cin >> l >> r;
        int ans = 0;
        for (int i = 0; i < cnt; i++)
            for (int j = p[i] * p[i]; j <= r; j *= p[i])
                if (j >= l) ans++;
        cout << ans << "\n";
    }
    return 0;
}
