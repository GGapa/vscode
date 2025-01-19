#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> vec, len;
    int top = 0;
    int sum = 0, rem = 0;
    rep(i, 1, n) {
        int op; cin >> op;
        int x; 
        if(op == 1) {
            cin >> x;
            vec.emplace_back(sum); len.emplace_back(x);
            sum += x;
        }
        else if(op == 2) rem += len[top], top++;
        else {
            cin >> x;
            cout << vec[top + x - 1] - rem << '\n';
        }
    }
    return 0;
}