//T351676 「RiOI-2」equals
//https://www.luogu.com.cn/problem/T351676?contestId=122184

#include <iostream>
#include <vector>
using namespace std;
#define int long long
const int maxn = 1e6 + 5 ;
int n;
int dep[maxn];
bool used[maxn];
int Sum = 0;
vector<int> G[maxn];
void dfs(int x, int dept) {
    dep[x] = dept;
    Sum += dept;
    for(auto to : G[x]) {
        if(dep[to] != 0) continue;
        dfs(to, dept + 1);
    }
}
void dfs1(int x, int sum) {
    if(sum == Sum / 2) {
        for(int i = 1; i <= n; i++)
            cout << (int)used[i] << " ";
        exit(0);
    }
    if(x > n || sum > Sum / 2) return;
    if(!used[x]) {
        used[x] = true;
        dfs1(x, sum + dep[x]);
        used[x] = false;
    }
    dfs1(x + 1, sum);


}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1,1);
    if(Sum % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    dfs1(1, 0);
}