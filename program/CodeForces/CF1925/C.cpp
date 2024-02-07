#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m, k;
char ch[N];
int vis[30];

void solve() {
    memset(ch, 0, sizeof(ch));
    memset(vis, 0, sizeof(vis));
    cin >> n >> k >> m;
    cin >> ch + 1;
    int res = 0, cnt = 0;
    string s;
    for(int i = 1; i <= m; i++) {
        if(cnt == n) 
            break;
        res += (vis[ch[i] - 'a'] == 0);
        vis[ch[i] - 'a'] = 1;
        if(res == k) {
            memset(vis, 0, sizeof(vis));
            s += ch[i];
            res = 0;
            cnt++;
        }
    }
    if(cnt == n) {
        cout << "yes\n";
        return ;
    }
    for(int i = 0; i < k ;i++) {
        if(vis[i] == 0) {
            for(; cnt < n; cnt++) s += (char)(i + 'a');
        }
    }
    cout << "no\n";
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--)solve();
    return 0; 
}