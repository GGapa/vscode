/*
Commando War
https://vjudge.csgrandeur.cn/contest/584210#problem/A
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1005;

struct Work {
    int pre, spd;
}work[maxn];

bool cmp(Work x, Work y) {
    return x.spd > y.spd;
}

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int it = 0;
    while(true) {
        cin >> n;
        it++;
        if (n == 0) break;
        for(int i = 1; i <= n; i++)
            cin >> work[i].pre >> work[i].spd;
        sort(work + 1, work + 1 + n, cmp);
        int ans1 = 0, ans2 = 0;
        for(int i = 1; i <= n; i++) {
            ans1 += work[i].pre;
            ans2 = max(ans2, ans1 + work[i].spd);
        }
        cout << "Case " << it << ": " << ans2 << endl;
    }
    return 0;
}
