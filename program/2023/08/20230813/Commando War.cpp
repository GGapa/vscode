//Commando War
//https://www.luogu.com.cn/problem/UVA11729
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=117&page=show_problem&problem=2829

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 10;
struct Work {
    int pre, spd;
}works[maxn];
bool cmp(Work x, Work y) {
    return x.spd > y.spd;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, it = 1;
    do {
        cin >> n;
        if(n == 0) break;
        for(int i = 1; i <= n;i ++) {
            cin >> works[i].pre >> works[i].spd;
        }
        sort(works + 1, works + 1 + n, cmp);
        int ans1 = 0, ans2 = 0;
        for(int i = 1; i <= n; i++) {
            ans1 += works[i].pre;
            ans2 = max(ans2, ans1 + works[i].spd);
        }
        cout << "Case " << it << ": " << max(ans1, ans2) << endl;
        it++;
    }while(n != 0);
    return 0;
}