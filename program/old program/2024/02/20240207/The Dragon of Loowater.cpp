//The Dragon of Loowater
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 1000 + 5;

int n, m;

struct srt {
    double j, f;
    bool operator<(const srt& x) const {
        return j / f > x.j / x.f;
    }
}a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double m;
    int n;
    for(; cin >> m >> n && n != -1 && m != -1; ) {
        rep(i, 1, n) cin >> a[i].j >> a[i].f;
        sort(a + 1, a + 1 + n);
        double ans = 0;
        for(int i = 1; i <= n && m > 0; i++) {
            const auto & A = a[i];
            if(m >= A.f) ans += A.j , m -= A.f;
            else ans += m / A.f * A.j, m = 0;
        }
        printf("%.3lf\n", ans);
    }
    return 0;
}   