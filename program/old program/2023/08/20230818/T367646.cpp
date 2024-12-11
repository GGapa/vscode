/*
T367646 Stack
https://www.luogu.com.cn/problem/T367646?contestId=126183
*/

#include <iostream>
using namespace std;
const int maxn = 5000 + 5;
const int mod = 998244353;
typedef long long ll;

int n, h, w;
int Map[maxn];



int ans = 0;

void dfs(int x) {
    if(Map[x] > h || x > w) {
        return ;
    }
    bool high = false, vecent = false;
    int sum = 0;
    for(int i = 1; i <= w; i++) {
        if(Map[i] == h) high = true;
        if(Map[i] == 0) vecent = true;
        sum += Map[i];
        if(sum > n) return;
    }
    if(high == true && sum == n && vecent == false) {
        ans++;
        ans %= mod;
    }
    Map[x]++;
    dfs(x);
    Map[x]--;
    dfs(x + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> h >> w;
    int tmp;
    tmp = n - w - h + 1;
    int high = tmp / (w - 1);
    tmp = tmp - (high * (w - 1));
    if(n > h * w || tmp < 0) {
        cout << 0 << endl;
        return 0;
    }
    if(n == h * w || tmp == 0) {
        cout << 1 << endl;
        return 0;
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}