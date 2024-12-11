/*
AtCoder abc202 E Count Descendants
https://vjudge.csgrandeur.cn/contest/584212#rank
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn =  2e5 + 5;

int n;
vector<int> G[maxn], dep[maxn];
int it;
int in[maxn], out[maxn];

void dfs(int x, int depth) {
    in[x] = it;
    dep[depth].push_back(it++);
    for(int to : G[x]) dfs(to, depth + 1);
    out[x] = it++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 2, tmp; i <= n; i++) {
        cin >> tmp;
        G[tmp].push_back(i);
    }
    dfs(1, 0);
    int T;
    cin >> T;
    while(T--) {
        int u, v;
        cin >> u >> v;
        cout << lower_bound(dep[v].begin(), dep[v].end(), out[u]) - lower_bound(dep[v].begin(), dep[v].end(), in[u])<< "\n";
    }
    return 0;
}