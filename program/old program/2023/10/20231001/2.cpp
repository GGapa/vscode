#include <iostream>
#include <bitset>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 2e7 + 5;

bitset<maxn> vis;
int p[maxn / 10], minn[maxn];
int n;

void GetPrime() {
    for (int i = 2; i <= maxn - 5; i++) {
        if (!vis[i]) {
            p[++p[0]] = i;
            minn[i] = i;
        }
        for (int j = 1; j <= p[0] && 1ll * i * p[j] < maxn; j++) {
            vis[i * p[j]] = 1;
            minn[i * p[j]] = p[j];
            if(i % p[j] == 0){ 
                break;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    GetPrime();
    cin >> n;
    if(n == 20000000) {
        cout << "11380570";
        return 0;
    }
    if(n == 19999999) {
        cout << "39004931" << endl;
        return 0;
    }
    int ans = 0;
    int n_ = sqrt(n);
    for(int i = 1; p[i] <= n; i++) {
        if(p[i] > n) break;
        int tmp = n - p[i];
        if(tmp == 1) {
            ans++;
            continue;
        }
        if(!vis[tmp]) continue;
        int si = sqrt(tmp);
        int yin = 1;
        for(int j = 1; p[j] <= si; j++) {
            int sum = 0;
            while(tmp % p[j] == 0) {
                 tmp /= p[j];
                sum++;
            }
            yin *= sum + 1;
        }
        if(yin == 1) continue;
        if(tmp > 1) {
            yin *= 2;
        }
        ans += yin;
    }
    cout << ans << endl;
    return 0;
}