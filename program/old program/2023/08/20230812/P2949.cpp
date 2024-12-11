//P2949 [USACO09OPEN] Work Scheduling G
//https://www.luogu.com.cn/problem/P2949
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;
int n;
struct Work {
    int d, p;
};
Work works[maxn];

priority_queue<int, vector<int>, greater<int> > que;

bool cmp(Work x, Work y) {
    return x.d == y.d ? x.p > y.p : x.d < y.d;
}

signed main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> works[i].d >> works[i].p;
    }
    int used = 0;
    long long ans = 0;
    sort(works + 1, works + 1 + n, cmp);
    que.push(works[1].p);
    ans += works[1].p;
    for(int i = 2; i <= n; i++) {
        if(works[i].d <= que.size() ) {
            if(works[i].p >= que.top()) {
            ans -= que.top();
            que.pop();
            ans += works[i].p;
            que.push(works[i].p);
            }
        }
        else {
            que.push(works[i].p);
            ans += works[i].p;
        }
    }
    cout << ans << endl;
    return 0;
}