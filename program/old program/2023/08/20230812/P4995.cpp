//https://www.luogu.com.cn/problem/P4995
//P4995 跳跳！
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 300 + 10;
long long ans = 0;
int n;
int a[maxn];
int main() {
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<int>());
    int l, r;
    l = 1;
    r = n;
    ans += a[1] * a[1];
    bool flag = true;
    while(l < r) {
        ans += pow((a[l] - a[r]), 2);
        if(flag) l++;
        else r--;
        flag = !flag;
    }
    cout << ans << endl;
    return 0;
}