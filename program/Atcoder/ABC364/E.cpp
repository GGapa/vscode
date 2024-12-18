#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int M = 20000 + 5, N = 80 + 5;
const int INF = 1e9;

int F[N][N][M];     // 1 - n 吃了 j 个食物，A 的和为 k 所得到的最小的 B;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    using AI = array<int, 2>;
    fill(F[0][0], F[0][0] + N * N * M, INF);
    F[0][0][0] = 0;
    int n; cin >> n;
    int x, y; cin >> x >> y;
    vector<AI> A(1), t;
    rep(i, 1, n) {
        int a, b; cin >> a >> b;
        if(a <= x && b <= y) A.push_back({a, b});
        else t.push_back({a, b});
    }
    sort(A.begin(), A.end(), [&](const AI &a, const AI &b) {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    });
    sort(t.begin(), t.end());
    for(auto a : t) A.push_back(a);
    int ans = 1;
    rep(j, 0, n) rep(i, 1, n) {
        per(k, x + 10001, 0) {
            auto &f = F[i][j][k];
            f = min(f, F[i - 1][j][k]);
            if(j == 0 || k - A[i][0] < 0) continue;
            if(F[i - 1][j - 1][k - A[i][0]] <= y && k - A[i][0] <= x) {
                f = min(f, F[i - 1][j - 1][k - A[i][0]] + A[i][1]), ans = max(ans, j);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}