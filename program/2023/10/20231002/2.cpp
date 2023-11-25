#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
const int maxn = 2000 + 5;

int n, x;
struct Day {
    int a, b, c;
}day[maxn];

int mw = 0;
int ans = 0;

bool cmp(Day u, Day v) {
    int tmp1 = max(u.c, u.b + min(u.b * 2, u.c));
    int tmp2 = max(v.c, v.b + min(v.b * 2, v.c));
    if(tmp1 == tmp2) 
        return u.a < u.c;
    return tmp1 > tmp2;
}

stack<int> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin  >> day[i].a >> day[i].b >> day[i].c;
        mw += day[i].a;
    }
    if(mw < x) {
        cout << -1 << endl;
        return 0;
    }
    mw = 0;
    sort(day + 1, day + 1 + n, cmp);
    int it = n;
    for(it; it >= 1 && mw < x; it--) {
        ans += day[it].a;
        mw += day[it].a;
    }
    if(mw < x) {
        cout << -1 << endl;
        return 0;
    }
    for(it = it; it >= 1; it--) {
        ans += max(day[it].c, day[it].b + min(day[it].b * 2, day[it].c));
    }
    cout << ans << endl;
    return 0;
}