#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

int n;
int a[N], cnt = 0;
bool vis[N];
vector<pair<int, int> > ans[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    bool tag = true;
    while(tag) {
        tag = false;
        cnt++;
        memset(vis, 0, sizeof(vis));
        rep(i, 1, n) {
            if(vis[i]) continue;
            vector<int> tmp;
            for(int j = i; !vis[j]; j = a[j]) {
                tmp.push_back(j); 
                vis[j] = true;
            }
            for(int l = 0, r = tmp.size() - 1; l < r; l++, r--) {
                ans[cnt].push_back({tmp[l], tmp[r]});
                swap(a[tmp[l]], a[tmp[r]]);
            }
            if(tmp.size() != 1) tag = true;
        }
    }
    cnt--;
    cout << cnt << '\n';
    rep(i, 1, cnt) {
        int tmp;
        cout << ans[i].size() << '\n';
        for(auto j : ans[i]) 
            cout << j.first << " " << j.second << '\n';
    }
    return 0;
}