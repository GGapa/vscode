#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

struct BIT {
    int n;
    vector<int> T;
    BIT(int _n) : n(_n) ,T(_n + 5) {    };
    int lowbit(int x) {return x & -x;}
    void add(int x, int v) {
        for(x; x <= n; x += lowbit(x)) T[x] += v;
    }
    ll ask(int x) {
        ll res = 0;                                 // 不赋初值见祖宗！！！！！ 
        for(; x > 0; x -= lowbit(x)) res += T[x];
        return res;
    }
};

const int N = 1e5 + 5;


int n, m, k;
using AI = array<int, 5>;
vector<AI> A(1);
BIT T(2e5 + 5);

bool cmp(const AI &x, const AI &y) {
    if(x[1] != y[1]) return x[1] < y[1];
    return x[2] < y[2];
}

void cdq(int l, int r) {
    if(l == r) return ;
    int mid = l + r >> 1;
    cdq(l, mid); cdq(mid + 1, r);
    sort(A.begin() + l, A.begin() + mid + 1, cmp);
    sort(A.begin() + mid + 1, A.begin() + r + 1, cmp);
    int i = l, j = mid + 1;
    for(; j <= r; j++) {
        for(; i <= mid && A[i][1] <= A[j][1]; i++) 
            T.add(A[i][2], A[i][3]);
        A[j][4] += T.ask(A[j][2]);
    };
    rep(k, l, i - 1) T.add(A[k][2], -A[k][3]);
    return ;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    vector<AI> tmp(n + 2);
    rep(i, 1, n) rep(j, 0, 2) cin >> tmp[i][j];
    sort(tmp.begin() + 1, tmp.begin() + 1 + n);
    for(int i = 1, t = 0; i <= n; i++) {
        t++;
        if(tmp[i] != tmp[i + 1]) {
            A.push_back(tmp[i]);
            A[A.size() - 1][3] = t;
            t = 0;
        }
    }
    int m = A.size() - 1;
    // rep(i, 1, m) cout << A[i][0] << " " << A[i][1] << " " << A[i][2] << '\n';
    cdq(1, m);
    vector<int> ans(n + 1);
    rep(i, 1, m) ans[A[i][4] + A[i][3] - 1] += A[i][3];
    rep(i, 0, n - 1) cout << ans[i] << '\n';
    return 0;
}
/*

*/