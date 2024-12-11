//T348741 『MGOI』Simple Round I | D. 魔法环
//https://www.luogu.com.cn/problem/T348741?contestId=101050
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
const int maxn = 3000 + 5;
#define int long long
int n, k;
int a[maxn];
bool used[maxn];
int check() {
    int SUM = 0;
    for(int i = 1; i <= n; i++) {
        if(used[i]) {
            SUM += a[i] * a[i];
        }
        else {
            int it1 = i, it2 = i;
            while(!used[it1]) {
                it1 = (it1 == n) ? 1 : (it1 + 1);
            }
            while(!used[it2]) {
                it2 = (it2 == 1) ? n : (it2 - 1);
            }
            if(a[it2] < a[it1]) {
                if(i < it1) SUM += (it1 - i) * a[it1];
                else SUM+= (n - i + it1) * a[it1];
            }
            if(a[it2] > a[it1]) {
                if(it2 < i) SUM += (i - it2) * a[it2];
                else SUM += (i + n - it2) * a[it2];
            }
        }
    }
    return SUM;
}
int ans = LLONG_MAX;
void dfs(int x,int sum) {
    if(x > n || sum > k) return ;
    if(sum == k) {
        ans = min(ans, check());
    }
    if(!used[x]) {
        used[x] = true;
        dfs(x, sum + 1);
        used[x] = false;
    }
    dfs(x + 1, sum);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}