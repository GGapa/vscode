// Fun Game

#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long

int overlap(const string & a, const string & b) { 
    int n1 = a.length(), n2 = b.length();
    rep(i, 0, n1 - 1){     
        if(n2 + i <= n1) continue;
        bool tag = true;
        rep(j, 0, n1 - i - 1) if(a[i + j] != b[j]) {
            tag = false;
            break;
        }  
        if(tag) return n1 - i;  
    }
    return 0;
}

const int N = 20;
int OL[N][N];     
int F[1 << N][N];   


void solve(vector<int> &L) {
    memset(F, -1, sizeof(F));
    auto update = [&](int &x, int v) { 
        if(x < 0 || v < x)
            x = v;
    };
    int n = L.size(), full = (1 << n) - 1;
    rep(i, 0, n - 1) F[(1 << i)][i] = L[i];
    rep(s, 1, full - 1)     
        rep(i, 0, n - 1)
        if(F[s][i] >= 0) 
            rep(j, 0, n - 1) if(!(s & (1 << j))) 
                update(F[s | (1 << j)][j], F[s][i] + L[j] - OL[i][j]);
    int ans = INT_MAX;
    rep(i, 0, n - 1) if(F[full][i] >= 0) 
        update(ans, F[full][i]);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n; 
        vector<string> A(n), S;
        for(auto &x : A) 
            cin >> x;
        sort(A.begin(), A.end(), [](const string &x, const string & y) {
            return x.size() < y.size();
        }); 
        vector<int> len; 
        // S = A;  
        // for(auto a : A) len.push_back(a.size());
        auto proc = [&](const string & x, int i) {
            rep(j, i + 1, n - 1) {
                const auto &y = A[j];
                if(y.find(x) != string::npos)
                    return ;
            }
            S.push_back(x), len.push_back(x.size());
        };
        rep(i, 0, n - 1) proc(A[i], i);
        n = S.size();
        
        rep(i, 0, n - 1) rep(j, 0, n - 1)
            OL[i][j] = overlap(S[i], S[j]);
        solve(len);
    return 0;
    
}