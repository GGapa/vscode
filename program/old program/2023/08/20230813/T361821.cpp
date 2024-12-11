//T361821 区间翻转区间异或和
//https://www.luogu.com.cn/problem/T361821?contestId=122758
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
#define int long long
typedef long long ll;
const int maxn = 1e5 + 5;
ll a[maxn], f[maxn];
unordered_map<ll, ll> M;
signed main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        f[i] = a[i] ^ f[i - 1];
        M[f[i]]++;
    }
    M[f[0]]++;
    ll ans = 0;
    for (auto& i : M) {
        ans += i.second * (i.second - 1) / 2; 
    }
    cout << ans << endl;
    return 0;
}
