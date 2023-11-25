//T363240 洗牌
//https://www.luogu.com.cn/problem/T363240?contestId=123906
#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;
int n, q;
int Next[maxn], Ahead[maxn];// 下一个  前一个
int pos[maxn];//位置
int val[maxn];
int main() {
    cin >> n >> q;
    Next[0] = 1;
    for(int i = 1; i <= n; i++) {
        cin >> val[i];
        Next[i] = i + 1;
        Ahead[i] = i - 1;
        pos[val[i]] = i;
    }
    Ahead[n + 1] = n;
    for(int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;
        l = pos[l];
        r = pos[r];
        Ahead[Next[r]] = Ahead[l];
        Next[Ahead[l]] = Next[r];
        Ahead[l] = Ahead[n + 1];
        Next[Ahead[n + 1]] = l;
        Ahead[n + 1] = r;
        Next[r] = n + 1;
    }
    int it = n + 1;
    for(int i = 1; i <= n; i++) {
        cout << val[it = Ahead[it]] << "\n "[i + 1 <= n];
    }
    return 0;
}