// USACO08DEC G Secret Message
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)

using namespace std;
const int N = 5e5 + 5;

int n, m, l;
int t[N][2], en[N], sum[N], x[N];
int cnt;

void modify() {
    int it = 0;
    rep(i, 1, l) {
        int& tmp = t[it][x[i]];
        if(tmp == -1) tmp = ++cnt;
        it = tmp;
        sum[it]++;
    }
    en[it]++;
}

int query() {
    int it = 0, res = 0;
    rep(i, 1, l) {
        int &tmp = t[it][x[i]];
        if(tmp == -1) return res;
        it = tmp;
        res += en[it];
    }
    return res - en[it] + sum[it];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(t, -1, sizeof(t));
    rep(i, 1, n) {
        cin >> l;
        rep(j, 1, l) cin >> x[j];
        modify();    
    }
    rep(i, 1, m) {
        cin >> l;
        rep(j, 1, l) cin >> x[j];
        cout << query() << '\n';
    }

    return 0;
}