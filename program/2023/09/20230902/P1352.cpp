/*
P1352 没有上司的舞会
https://www.luogu.com.cn/problem/P1352
*/

#include <iostream>
#include <vector>
using namespace std;
const int maxn = 6e3 + 5;

int n;
int h[maxn];
bool isRoot[maxn];
vector<int> son[maxn];
int f[maxn][2];

void dp(int x) {
    f[x][0] = 0;
    f[x][1] = h[x];
    for(int i = 0; i < son[x].size(); i++) {
        int y = son[x][i];
        dp(son[x][i]);
        f[x][0] += max(f[son[x][i]][0],f[son[x][i]][1]);
        f[x][1] += f[son[x][i]][0];
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1, x, y; i <= n - 1; i++) {
        cin >> x >> y;
        son[y].push_back(x);
        isRoot[x] = true;
    }
    int root;
    for(int i = 1; i <= n; i++) 
        if(!isRoot[i]) {root = i; break;}
    dp(root);
    cout << max(f[root][0], f[root][1]) << endl;
    return 0;
}