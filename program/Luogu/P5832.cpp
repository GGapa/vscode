/*
P5832 [USACO19DEC] Where Am I? B
https://www.luogu.com.cn/problem/P5832
*/
#include <iostream>
using namespace std;

int ans = 0;
int n;
string a;

void check(int it1, int it2) {
    int tmp = 1;
    while(it1 < a.length() && it2 < a.length()) {
        if(a[++it1] == a[++it2]) tmp++;
        else break;
    }
    ans = max(ans, tmp);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> a;
    for(int i = 0; i < a.length(); i++) {
        for(int j = i + 1; j < a.length(); j++)  {
            if(a[i] != a[j]) continue;
            check(i, j);
        }
    }
    cout << ans + 1<< "\n";
    return 0;
}
/*
编程语言
C++14 (GCC 9)
代码长度
696B
用时
31ms
内存
856.00KB

2023-10-04 16:02:02
*/