#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

#ifdef _WIN32
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
#else
random_device gen;
mt19937 rnd(gen());
#endif

int rng(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rnd);
}

struct Mat {
    int l, d, r, u;
    friend Mat operator&(const Mat &x, const Mat &y) {
        return Mat{max(x.l, y.l), max(x.d, y.d), min(x.r, y.r), min(x.u, y.u)};
    }
    friend bool operator|(const Mat &x, const Mat &y) {
        return x.u >= y.d && y.u >= x.d && x.r >= y.l && y.r >= x.l;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, k; cin >> n >> k;
    vector<Mat> A(n);    
    for(auto &[l, d, r, u] : A) cin >> l >> d >> r >> u;

    while(1) {
        vector<Mat> B;
        rep(i, 0, k - 1) B.emplace_back(A[i]);
        rep(i, k, n - 1) {
            int it = -1;
            rep(j, 0, k - 1) if(A[i] | B[j]) {
                it = j;
                break;
            }
            if(it == -1) {
                swap(A[i], A[rng(0, i - 1)]);
                goto end;
            }
            B[it] = B[it] & A[i];
        }
        for(auto [l, d, r, i] : B) cout << l << " " << d << '\n';
        return 0;
        end:;
    }

    return 0;
}