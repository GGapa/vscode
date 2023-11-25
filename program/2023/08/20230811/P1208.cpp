//P1208 [USACO1.3] 混合牛奶 Mixing Milk
//https://www.luogu.com.cn/problem/P1208
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e6 + 5;
int n, m;
struct AA
{
    int p, a;
}person[maxn];
bool cmp(AA x, AA y) {
    return x.p < y.p;
}
int main( ) {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> person[i].p >> person[i].a;
    }
    int ans = 0;
    sort(person + 1, person + 1 + m, cmp);
    for(int i = 1; i <= m; i++) {
        ans += min(person[i].a, n)*person[i].p;
        n -= person[i].a;
        if(n <= 0) 
            break;
    }
    cout << ans << endl;
    return 0;
}