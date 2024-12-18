//P1803 凌乱的yyy / 线段覆盖
//https://www.luogu.com.cn/problem/P1803
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 5;
struct AA {
    int a, b;
}exam[maxn];
int n;

bool cmp(AA x, AA y) {
    return x.b < y.b;
}

int main( ) {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> exam[i].a >> exam[i].b;
    }
    int ans = 0;
    int bef = 0;
    sort(exam + 1, exam + 1 + n, cmp);
    for(int i = 1; i <= n; i++) {
        if(bef <= exam[i].a) {
            ans++;
            bef = exam[i].b;
        }
    }
    cout << ans << endl;
    return 0;
}