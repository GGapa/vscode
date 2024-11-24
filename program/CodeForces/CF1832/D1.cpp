// 不会吧不会吧，我不会要赛后过题了吧 QAQAQAQ
// 不会吧不会吧，我不会要赛后过题了吧 QAQAQAQ
// 不会吧不会吧，我不会要赛后过题了吧 QAQAQAQ
// 不会吧不会吧，我不会要赛后过题了吧 QAQAQAQ
// 不会吧不会吧，我不会要赛后过题了吧 QAQAQAQ
// 不会吧不会吧，我不会要赛后过题了吧 QAQAQAQ
// 不会吧不会吧，我不会要赛后过题了吧 QAQAQAQ
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    vector<LL> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    sort(A.begin(), A.end());
    auto check = [&](int k) {
        auto B = A; B[0] = -1e18;
        if(k <= n)  for(int i = 1, j = k; i <= n && j; i++, j--) B[i] += j;
        else {
            for(int i = n - ((k - n) & 1), j = k - n + 1 + ((k - n) & 1); i >= 1; i--, j++) B[i] += j;
            sort(B.begin() + 1, B.end());
            for(int i  = n, t = (k - n + 1) / 2, cnt = 1; i >= 1 && t; i--, cnt++) {
                if(t > (B[i] - B[i - 1]) * cnt) t -= (B[i] - B[i - 1]) * cnt;
                else {
                    for(int j = i + 1; j <= n - ((k - n) & 1); j++) B[j] = B[i] - (t / cnt);
                    B[i] = B[i] - (t / cnt);
                    for(int j = i; j < i + t % cnt; j++) B[j]--;
                    break;
                }
            }
        }
        return *min_element(B.begin() + 1, B.end());
    };
    for(int i = 1, k; i <= q;i ++) {
        cin >> k;
        if(n == 1) {
            cout << A[1] + (k & 1 ? 1 : -1) * ((k + 1) / 2) << " \n"[i == q];   // debug 向上取整
            continue;
        }
        cout << check(k) << " \n"[i == q];
    }
    return 0;
}
/* 
考虑对于每个询问，二分最小值，当且仅当填完所有的数之后剩下的 k 是奇数，或者，
3 1
139372258 302094278 664187073 
364766632 
*/