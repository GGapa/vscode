#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

struct BIT {
    int n;
    vector<int> T;
    BIT(int _n) : n(_n) ,T(_n + 5) {    };
    int lowbit(int x) {return x & -x;}
    void add(int x, int v) {
        for(x; x <= n; x += lowbit(x)) T[x] += v;
    }
    LL ask(int x) {
        LL res = 0;                                 // 不赋初值见祖宗！！！！！ 
        for(; x > 0; x -= lowbit(x)) res += T[x];
        return res;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;   
    vector<int> A(n + 1), mx(n + 1);
    rep(i, 1, n) cin >> A[i];
    BIT T(n);
    rep(i ,1, n) {
        if(T.ask(n) / n >= A[i]) {
            mx[i] = n;                
            continue;
        }
        int l = 1, r = n, as;
        while(l <= r) {
            int mid = l + r >> 1; 
            if(T.ask(mid) / mid + 1 <= A[i]) r = mid - 1, as = mid;
            else l = mid + 1;
        }
        mx[i] = as;
        T.add(as, 1);
    }
    for(int i, x; q--; ) {
        cin >> i >> x;
        cout << (x >= mx[i] ? "YES\n" : "NO\n");
    }
    return 0;
}