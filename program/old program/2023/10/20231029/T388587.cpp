#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;

int T, n;
pair<int, int> a[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--) {   
        cin >> n;
        a[0].first = a[0].second = a[n + 1].first = a[n + 1].second = 0;
        for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
        bool flag = true;
        int x = 0, y = 1;
        // while(flag || (x != 0 && x != n + 1)) {
        //     x += y;
        //     flag = false;
        //     if(y == 1 && a[x].first > 0) {
        //         y = -1;
        //         a[x].first--;
        //     }
        //     else if(y == -1 && a[x].second > 0) {
        //         y = 1;
        //         a[x].second--;
        //     }
        // }
        int suma, sumb;
        suma = sumb = 0;
        for(int i = 0; i <= n; i++) {
            suma += a[i+1].first;
            sumb += a[i].second;
            if(suma > sumb) {
                flag = false;
                break;
            }
        }
        cout << (flag ? n+1 : 0) << "\n";
    }
    return 0;
}
/*
编程语言
C++14 (GCC 9)
代码长度
1.19KB
用时
393ms
内存
1.11MB
 GGapa

所属题目
T388587 wbyblD
所属比赛
GenshinOI Round 3
评测状态
Accepted
评测分数
100
提交时间
2023-10-29 15:36:47
*/