/**
 * @Problem      : P1512 伊甸园日历游戏
 * @URL          : https://www.luogu.com.cn/problem/P1512
 * @Author       : GGapa
 * @Date         : 2023-11-17 18:57:22
 * @LastEditTime : 2023-11-17 19:00:36
**/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freoepn("akioi.in", "r", stdin);
    // freopen("akioi.out", 'w', stdout);
    int t, x, y, z;
    cin >> t;
    while(t--) {
        cin >> x >> y >> z;
        if((y == 9 && z == 30) || (y == 1 && z == 30) || ((y + z) % 2 == 0)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}