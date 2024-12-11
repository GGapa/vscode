//P4549 【模板】裴蜀定理
//https://www.luogu.com.cn/problem/P4549
#include <iostream>
#include <cmath>
using namespace std;
int n;
int a;
int gcd(int x, int y) {
    if(y == 0) {
        return x;
    }
    return gcd(y, x % y);
}
int main() {
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        a = abs(a);
        ans = gcd(ans , a);
    }
    cout << ans << endl;
    return 0;
}