// 14:20
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
// #define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 2e5 + 5;

int n, q; LL w;
int A[N]; 

struct fenwick {
    int n;
    struct BIT {
        int n;
        vector<LL> T;
        BIT(int _n) : n(_n) ,T(_n + 5) {    };
        int lowbit(int x) {return x & -x;}
        void modify(int x, LL v) {
            for(x; x <= n; x += lowbit(x)) T[x] += v;
        }
        LL query(int x) {
            LL res = 0;
            for(; x > 0; x -= lowbit(x)) res += T[x];
            return res;
        }
    };
    BIT T1, T2;
    fenwick(int _n) : n(_n), T1(n), T2(n) { }
    void modif(int x, LL v) { T1.modify(x, 1ll * (x - 1) * v); T2.modify(x, v); }
    LL quer(int y) { return T2.query(y) * y - T1.query(y); }
    void modify(int l, int r, LL v) { modif(l ,v); modif(r + 1, -v); }
    LL query(int l, int r) { return quer(r) - quer(l - 1); }
};


signed main() {
//     freopen("test.in", "r", stdin);
//     freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q >> w;
    rep(i, 1, n) cin >> A[i];
    vector<LL> pw(62, 0);
    fenwick tr(n);
    pw[0] = 1;
    rep(i, 1, 60) pw[i] = pw[i - 1] * 2;
    rep(j, 1, n) tr.modify(j, j, A[j]);
    for(int l, r, d; q--; ) {
        cin >> l >> r >> d;
        tr.modify(l, r, d); 
        int it = 0; LL t;
        for(LL i = 1, sum = 0, all = tr.query(1, n); ; i++){
            it = i;
            if(sum + all * pw[i - 1] >= w) {
                t = w - sum;
                int ll = 1, rr = n, ans = 0;
                while(ll <= rr) {
                    int mid = ll + rr >> 1;
                    if(tr.query(1, mid) * pw[it - 1] >= t) rr = mid - 1;
                    else ll = mid + 1, ans = mid;
                }
                cout << (it - 1) * n + ans << '\n';
                break;
            }
            sum += all * pw[i - 1];
            
        }
    }
    return 0;
}
/*
其实根本不需要对于每一个东西都开上一个 BIT，可以直接乘。
*/
