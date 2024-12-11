#include <bits/stdc++.h>
#include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
using ULL = unsigned long long;
const int p = 13331, N = 1000 + 5;

ULL XP[N];

struct Hash {
    int n, nw = 1; vector<ULL> H; vector<int> A;
    Hash() {
        cin >> n; H.resize(n + 2), A.resize(n + 1);
        // cout << n << endl;
        rep(i, 1, n) cin >> A[i], H[i] = H[i - 1] * p + A[i];
    }
    ULL chash(int l) const {
        int r = nw + l - 1;
        return H[r] - H[nw - 1] * XP[r - nw + 1];
    }
    bool operator>(const Hash &o) const {
        int l = 1, r = min(o.n - o.nw + 1, n - nw + 1), res = -1;
        while(l <= r) {
            int mid = l + r >> 1;
            if(chash(mid) != o.chash(mid)) r = mid - 1, res = mid;
            else l = mid + 1;
        }
        if(res != -1) return A[res + nw - 1] > o.A[res + o.nw - 1];
        return n - nw < o.n - o.nw;
    }
};

vector<Hash> HH;

struct Item {
    int x;
    Item(int _x) {x = _x;}
    bool operator<(const Item &o) const {
        return HH[x] > HH[o.x];
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    XP[0] = 1;
    rep(i, 1, N - 1) XP[i] = XP[i - 1] * p;
    priority_queue<Item> q;
    for(int i = 1; i <= n; i++) HH.push_back(Hash()), q.push(Item(i - 1));
    while(!q.empty()) {
        Item x = q.top(); q.pop();
        Hash &t = HH[x.x];
        cout << t.A[t.nw++] << ' ';
        if(t.nw <= t.n) q.push(x);
    }
    return 0;
}