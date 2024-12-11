#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;

int T, n, m, p;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    rep(_, 1, T) {
        cin >> n >> m >> p;
        if(n >= p && m >= p) {
            cout << "Lasting Battle\n";
            continue;
        }
        else if(m >= p) {
            cout << "Bob\n";
            continue;
        }
        else {
            cout << "Alice\n";
        }
    }
    return 0;
}