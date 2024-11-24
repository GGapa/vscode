#include <bits/stdc++.h>

#define x first
#define y second
using namespace std;

const int N = 1000010;

typedef long long ll;
typedef pair<int, int> PII;

int n, k, q, type;
ll suma[N], sumb[N];
PII dp[21][N];
int log_2[N];

void init_log_2() {
    log_2[1] = 0;
    for(int i = 2; i <= n; i++)
        log_2[i] = log_2[i / 2] + 1;
}

inline PII cmp(PII a, PII b) {
    if(!a.x && !a.y) return b;
    if((ll)a.x * b.y < (ll)b.x * a.y) return b;
    return a;
}

ll gcd(ll a, ll b) {
    if(!b) return a;
    return gcd(b, a % b);
}
struct ST_table{
	PII f[21][N];
	void init() {
	    for(int j = 1; j <= log_2[n]; j++)
	        for(int i = 1; i + (1 << j) - 1 <= n; i++)
	            f[j][i] = cmp(f[j - 1][i], f[j - 1][i + (1 << j - 1)]);
	}
	inline PII query(int l, int r) {
	    int t = log_2[r - l + 1];
	    return cmp(f[t][l], f[t][r - (1 << t) + 1]);
	}
}st;

int main() {
    scanf("%d%d%d%d", &n, &k, &q, &type);
    init_log_2();
    for(int i = 1; i <= n; i++) {
        scanf("%d", &suma[i]);
        suma[i] += suma[i - 1];
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &sumb[i]);
        sumb[i] += sumb[i - 1];
    }
    for(int len = k; len <= k * 2; len++)
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            int sa = suma[r] - suma[l - 1];
            int sb = sumb[r] - sumb[l - 1];
            PII tmp = {sa, sb};
            if(len > k) dp[len - k][l] = cmp(cmp(dp[len - k - 1][l], dp[len - k - 1][l + 1]), tmp);
            else dp[len - k][l] = tmp;
        }
    for(int i = 1; i <= n - k + 1; i++)
        for(int j = i + k - 1; j <= min(i + k * 2 - 1, n); j++)
            st.f[0][i] = cmp(st.f[0][i], {suma[j] - suma[i - 1], sumb[j] - sumb[i - 1]});
    st.init();
    int l, r, lasans = 0;
    while(q--) {
        scanf("%d%d", &l, &r);
        l = (l ^ (lasans * type)) % n + 1, r = (r ^ (lasans * type)) % n + 1;
        if(l > r) swap(l, r);
        if(r - l + 1 < k) {
            printf("0/1\n");
            lasans = 0;
            continue;
        }
        PII ans = {0, 0};
        int limit = r - 2 * k + 1;
        if(limit >= l) ans = st.query(l, limit);
        else limit = l - 1;
        ans = cmp(ans, dp[r - limit - k][limit + 1]);
        int d = gcd(ans.x, ans.y);
        ans.x /= d, ans.y /= d;
        printf("%d/%d\n", ans.x, ans.y);
        lasans = ans.x;
    }
    return 0;
}