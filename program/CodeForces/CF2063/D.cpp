#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

template<int siz>
using AI = array<int, siz>;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> A(n + 1), B(m + 1);
    rep(i ,1, n) cin >> A[i];
    rep(i, 1, m) cin >> B[i];
    sort(A.begin() + 1, A.end());
    sort(B.begin() + 1, B.end());

    vector<LL> ans;  
    priority_queue<int, VI, greater<int>> qa, qb;

    int la, ra, lb, rb; la = lb = 1, ra = n, rb = m;
    int rea, reb; rea = n, reb = m;        // 剩余的空节点。
    LL sum = 0;
    for(int siz = 0, now = 0; ; ) {
        if(reb == 0 && qb.size()) sum -= qb.top(), qb.pop(), reb += 2, now--, rea++;
        else if(!reb) break;
        if(rea == 0 && qa.size()) sum -= qa.top(), qa.pop(), rea += 2, now--, reb++;
        else if(!rea)break;
        if(A[ra] - A[la] > B[rb] - B[lb] && ra > la && rea >= 2) {
            reb -= 1; rea -= 2; 
            sum += A[ra] - A[la]; 
            qa.emplace(A[ra] - A[la]);
            la++; ra--; now++;
        }  
        else if(rb > lb && reb >= 2){
            rea -= 1; reb -= 2; 
            sum += B[rb] - B[lb];
            qb.emplace(B[rb] - B[lb]);
            lb++; rb--; now++;
        }
        else if(ra > la && rea >= 2) {
            reb -= 1; rea -= 2; 
            sum += A[ra] - A[la]; 
            qa.emplace(A[ra] - A[la]);
            la++; ra--; now++;
        }
        else break;
        if(now > siz) ans.emplace_back(sum), siz++;
    }
    cout << ans.size() << '\n';
    for(auto a : ans) cout << a << " ";
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
} 