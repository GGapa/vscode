#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;

int size[N], hson[N], t[N], w[N];
vector<int> G[N];
ll f[N];
int n, sn;


int lowbit(int x) {
    return x & -x;
}
void add(int x, int v) {
    while(x <= n) {
        t[x] += v;
        x += lowbit(x);
    }
}
int qurey(int x) {
    int tmp = 0;
    while(x >= 1) {
        tmp += t[x];
        x -= lowbit(x);
    }
    return tmp;
}

void dfs1(int x, int fa) {
    size[u] = 1; add(u, 1);
    f[1] += qurey(n) - qurey(u);
    for(auto to : G[x]) {
        if(to == fa) continue;
        dfs1(to, x);
        size[x] += size[to];
        if(size[to] > size[hson[x]]) hson[x] = to;
    }
    add(u, -1);
}
void dfs2(int x, int fa) {
    for(auto to : G[x]) {
        if(to == fa || to == hson[x]) continue;
        dfs2(to, x);
        add(to, u - 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}