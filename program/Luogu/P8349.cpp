#include <bits/stdc++.h>
#include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;

template<int siz>
using AI = array<int, siz>;

constexpr int N = 1e6 + 5;

int n; 
int B[N];
vector<int> pos[N];
set<int> s[N];

namespace SS {
    int A[N], c[N];
    cc_hash_table<int, LL> mn;

    LL solve(int x, int y) {
        int cnt = 0;

        {
            int i = 0, j = 0;
            while(i < pos[x].size() && j < pos[y].size()) {
                cnt++;
                if(pos[x][i] < pos[y][j]) A[cnt] = pos[x][i++], c[cnt] = 1;
                else A[cnt] = pos[y][j++], c[cnt] = -1;
            }
            while(i < pos[x].size()) A[++cnt] = pos[x][i++], c[cnt] = 1;
            while(j < pos[y].size()) A[++cnt] = pos[y][j++], c[cnt] = -1;
        }
        
        LL sum = 0, ans = LLONG_MIN;
        mn.clear(); mn[0] = 0;
        for(int i = 1, s = 0; i <= cnt; i++) {
            s += c[i]; sum += B[A[i]];
            if(mn.find(s) != mn.end()) {
                ans = max(ans, sum - mn[s]);
                mn[s] = min(mn[s], sum);
            }
            else mn[s] = sum;
        }
        return ans;
    }
};

namespace BB {
    map<AI<2>, LL> ans;

    LL solve(int x, int y) {
        if(ans.count({x, y})) return ans[{x, y}];
        else return ans[{x, y}] = SS::solve(x, y);
    }
}

namespace SB {
    AI<2> A[N];
    vector<set<int>::iterator> del;
    cc_hash_table<int, LL> mn;

    LL solve(int x, int y) {
        int cnt = 0;
        for(auto i : pos[x]) {
            A[++cnt] = {i, 1};
            auto it = s[y].lower_bound(i); 
            if (it != s[y].begin()) {
                it--, del.emplace_back(it), A[++cnt] = {*it, -1};
                if (it != s[y].begin()) it--, del.emplace_back(it), A[++cnt] = {*it, -1}, it++;
                it++;
            }
            if (it != s[y].end()) {
                del.emplace_back(it), A[++cnt] = {*it, -1}; it++;
                if (it != s[y].end()) del.emplace_back(it), A[++cnt] = {*it, -1};
            }
            for (auto i : del) s[y].erase(i); 
            vector<set<int>::iterator>(0).swap(del);
        }

        sort(A + 1, A + 1 + cnt);

        LL sum = 0, ans = LLONG_MIN;
        mn.clear(); mn[0] = 0;
        for(int i = 1, ss = 0; i <= cnt; i++) {
            ss += A[i][1]; sum += B[A[i][0]];
            if(mn.find(ss) != mn.end()) {
                ans = max(ans, sum - mn[ss]);
                mn[ss] = min(mn[ss], sum);
            }
            else mn[ss] = sum;
            if(A[i][1] == -1) s[y].emplace(A[i][0]);
        }
        return ans;
    }
}

signed main() {
    // freopen("test.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q; cin >> n >> q;
    for(int i = 1, a; i <= n; i++)
        cin >> a, pos[a].emplace_back(i), s[a].insert(i);
    rep(i, 1, n) cin >> B[i];

    constexpr int B = 500;
    for(int x, y; q--; ) {
        cin >> x >> y;
        if(pos[x].size() > pos[y].size()) swap(x, y);
        if(pos[y].size() < B) cout << SS::solve(x, y);
        else if(pos[x].size() > B) cout << BB::solve(x, y);
        else cout << SB::solve(x, y);
        cout << '\n';
    } 
    return 0;
}
/*
感觉是一个根号题，如果不同种类额数的数量 ＞ B，对于每一个询问直接暴力做，O(nB) 
如果不同种类的数量 < B O(B^2 * n)，考虑构造出一个和数字数量的做法。
*/