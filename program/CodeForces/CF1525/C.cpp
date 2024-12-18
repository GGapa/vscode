//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

struct Node {
    int it, id;
    char c;
    Node() {}
    Node(int _it, char _c, int _id)  {it = _it, c = _c, id  = _id;}
};
const int N = 3e5 + 5;
vector<int> ans;

void solve() {
    int m;
    auto work = [&](vector<Node> &A) {
        sort(A.begin() + 1, A.end(), [](const Node &x, const Node &y) {
            return x.it < y.it;
        });
        list<int> st;
        int nn = A.size() - 1;
        rep(i, 1, nn) {
            if(st.empty()) st.push_back(i);
            else {
                int p = st.back();
                if(A[p].c == 'R' && A[i].c == 'L') {
                    ans[A[p].id] = ans[A[i].id] = abs(A[i].it - A[p].it) / 2;  
                    st.pop_back();     
                }
                else {
                    st.push_back(i);
                }
            }
        }
        auto sL = [&]() {
            while(st.size() >= 2 && A[*st.begin()].c == 'L' && A[*++st.begin()].c == 'L')  {
                auto x = A[*st.begin()]; st.pop_front();
                int res = x.it;
                auto y = A[*st.begin()]; st.pop_front();
                res += (y.it - res) / 2;
                ans[x.id] += res;
                ans[y.id] += res;
            }
        };
        auto sR = [&]() {
            while(st.size() >= 2 && A[*st.rbegin()].c == 'R' && A[*++st.rbegin()].c == 'R')  {
                auto x = A[*st.rbegin()]; st.pop_back();
                int res = m - x.it;
                auto y = A[*st.rbegin()]; st.pop_back();
                res += (m - (y.it + res)) / 2;
                ans[x.id] += res ;
                ans[y.id] += res;
            }
        };
        sL(); sR();
        if(st.size() >= 2 && A[*st.begin()].c == 'L' && A[*st.rbegin()].c == 'R') {
            auto &x = A[*st.begin()], &y = A[*st.rbegin()];
            if(x.it <= m - y.it) {
                // y.it = 2 * m - y.it;
                // ans[x.id] += x.it; ans[y.id] += y.it;
                x.it *= -1, x.c = 'R';
                sR();
            }
            else {
                // ans[x.id] += m - y.it; ans[y.id] += m - y.it;
                // x.it -= m - y.it;
                y.it = 2 * m - y.it, y.c = 'L';
                sL();
           }
        }
    };
    int n; cin >> n >> m ;
    ans.assign(n + 1, 0);
    vector<Node> A(1), B(1);
    vector<int> X(n + 1);
    vector<char> C(n +1);
    rep(i, 1, n) cin >> X[i];
    rep(i, 1, n) cin >> C[i];
    rep(i, 1, n) {
        int x = X[i]; char c = C[i]; 
        (x % 2 ? A : B).push_back(Node(x, c, i));
    }
    work(A); work(B);
    rep(i, 1, n) cout << (ans[i] == 0 ? -1 : ans[i]) << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}