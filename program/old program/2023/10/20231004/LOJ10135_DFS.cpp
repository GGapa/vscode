/*
LOJ10135
https://loj.ac/p/10135
*/
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 4e4 + 5;

int n, m, root;
vector<int> G[maxn];
int ti;
int in[maxn], out[maxn];

void dfs(int x) { //求解DFS序
    if(in[x] != 0) return;
    in[x] = ++ti; 
    for(int to : G[x]) dfs(to);
    out[x] = ++ti;
}

int ask(int x, int y) { //判断是否为祖先
    return in[x] < in[y] && in[y] < out[y] && out[y] < out[x];
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1, u, v; i <= n; i++) {
        cin >> u >> v;
        if(v == -1) {
            root = u;
            continue;
        }
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(root);
    cin >> m;
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        if(ask(u, v)) cout << 1 << "\n";
        else if(ask(v, u)) cout << 2 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
} 