
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)

using namespace std;
const int N = 1e5 + 5;


int t[N * 32][2], a[N * 32];
int n, cnt, m, tt;

void modify(int x) {
    int it = 0;

    per(i, 31, 0) {
        int tmp = (x >> i) & 1;
        if(!t[it][tmp]) t[it][tmp] = ++cnt;
        it = t[it][tmp];
    }
    a[it] = x;
}

int query(int x) {
    int it = 0;
    per(i, 31, 0) {
        int tmp = (x >> i) & 1;
        if(t[it][tmp ^ 1]) it = t[it][tmp ^ 1];
        else it = t[it][tmp];
    }
    return a[it];
}

void solve() {
    memset(t, 0 ,sizeof(t));
    cnt = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1, tmp; i <= n; i++) {
        scanf("%d", &tmp);
        modify(tmp);
    }
    printf("Case #%d:\n", ++tt);
    for(int i = 1, tmp; i <= m; i++) {
        scanf("%d", &tmp);
        printf("%d\n", query(tmp));
    }
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T; scanf("%d", &T);
    while(T--) solve();
    return 0;
}