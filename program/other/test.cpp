#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

constexpr int N = 3e5 + 10, L = 500;
constexpr ll inf = 9e18;

int n, q, b[N];

vector<int> p[N];
set<int> s[N];

namespace SS {
    int cnt, a[N], c[N];
    unordered_map<int, ll> mn;

    ll solve(int x, int y) {
        cnt = 0; int i = 0, j = 0;
        while (i < p[x].size() && j < p[y].size()) {
            cnt++;
            if (p[x][i] < p[y][j]) a[cnt] = p[x][i++], c[cnt] = 1;
            else a[cnt] = p[y][j++], c[cnt] = -1;
        }
        while (i < p[x].size()) a[++cnt] = p[x][i++], c[cnt] = 1;
        while (j < p[y].size()) a[++cnt] = p[y][j++], c[cnt] = -1;
        int s = 0; ll sum = 0, ans = -inf;
        mn.clear(), mn[0] = 0;
        for (int i = 1; i <= cnt; i++) {
            s += c[i], sum += b[a[i]];
            if (mn.find(s) != mn.end()) {
                ans = max(ans, sum - mn[s]);
                mn[s] = min(mn[s], sum);
            } else mn[s] = sum;
        }
        return ans;
    }
}

namespace BB {
    int cnt, a[N], c[N];
    map<pii, ll> mem;
    
    ll solve(int x, int y) {
        if (mem.find(pii(x, y)) != mem.end()) return mem[pii(x, y)];
        return mem[pii(x, y)] = SS::solve(x, y);
    }
}

namespace SB {
    int cnt;
    struct Node {
        int p, c;
        bool operator<(const Node &rhs) const {return p < rhs.p;}
    } a[N];

    vector<set<int>::iterator> del;
    
    unordered_map<int, ll> mn;

    ll solve(int x, int y) {
        cnt = 0;
        for (int i : p[x]) {
            a[++cnt] = {i, 1};
            auto it = s[y].upper_bound(i);
            if (it != s[y].begin()) {
                it--, del.emplace_back(it), a[++cnt] = {*it, -1};
                if (it != s[y].begin()) it--, del.emplace_back(it), a[++cnt] = {*it, -1}, it++;
                it++;
            }
            if (it != s[y].end()) {
                del.emplace_back(it), a[++cnt] = {*it, -1}; it++;
                if (it != s[y].end()) del.emplace_back(it), a[++cnt] = {*it, -1};
            }
            for (auto i : del) s[y].erase(i); del.clear();
        }
        sort(a + 1, a + cnt + 1);
        int sc = 0; ll sum = 0, ans = -inf;
        mn.clear(), mn[0] = 0;
        for (int i = 1; i <= cnt; i++) {
            sc += a[i].c, sum += b[a[i].p];
            if (mn.find(sc) != mn.end()) {
                ans = max(ans, sum - mn[sc]);
                mn[sc] = min(mn[sc], sum);
            } else mn[sc] = sum;
            if (a[i].c == -1) s[y].emplace(a[i].p);
        }
        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> q;
    for (int i = 1, a; i <= n; i++) cin >> a, p[a].emplace_back(i), s[a].emplace(i);
    for (int i = 1; i <= n; i++) cin >> b[i];
    while (q--) {
        int x, y; cin >> x >> y;
        if (p[x].size() > p[y].size()) swap(x, y);
        if (p[y].size() <= L) cout << SS::solve(x, y) << '\n';
        else if (p[x].size() > L) cout << BB::solve(x, y) << '\n';
        else cout << SB::solve(x, y) << '\n';
    }
    return 0;
}