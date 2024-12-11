#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

const int N = 1500 + 5;

namespace AC {
    const int SZ = N * 100;
    int tot, tr[SZ][26];
    int fail[SZ], idx[SZ], val[SZ];
    int cnt[N];

    void init() {
        memset(fail, 0, sizeof(fail));
        memset(tr, 0, sizeof(tr)) ;
        memset(val, 0, sizeof(val));
        memset(idx, 0, sizeof(idx));
        memset(cnt, 0, sizeof(cnt));
        tot = 0;
    }

    void insert(const string &s, int id) {
        int u = 0;
        rep(i, 0, (int)s.size() - 1) {
            if(!tr[u][s[i] - 'a']) tr[u][s[i] - 'a'] = ++tot;
            u = tr[u][s[i] - 'a'];
        }
        idx[u] = id;
    }

    queue<int> q;

    void bulid() {
        rep(i, 0, 25) if(tr[0][i]) q.push(tr[0][i]);
        while(!q.empty()) {
            int x = q.front(); q.pop(); 
            rep(i, 0, 25) {
                if(tr[x][i]) fail[tr[x][i]] = tr[fail[x]][i], q.push(tr[x][i]);
                else tr[x][i] = tr[fail[x]][i];
            }
        }
    }

    int query(const string &s) {
        int u = 0, ret = 0;
        rep(i, 0, (int)s.size() - 1) {
            u = tr[u][s[i] - 'a'];
            for(int j = u; j; j = fail[j]) val[j]++;
        }
        rep(i ,0, tot) if(idx[i]) 
            ret = max(ret, val[i]), cnt[idx[i]] = val[i];
        return ret;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int n; cin >> n && n; ) {
        AC::init();
        vector<string> s(n + 1);
        string t;
        rep(i, 1, n) cin >> s[i], AC::insert(s[i], i);
        AC::bulid();
        cin >> t;
        int x = AC::query(t);
        cout << x << '\n';
        rep(i, 1, n) if(AC::cnt[i] == x) cout << s[i] << '\n';
    }
    return 0;
}