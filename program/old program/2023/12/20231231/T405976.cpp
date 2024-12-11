#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;

bool solve(int p, int a, int b, int c) {
    if(b != 0 || c == 0) return true;
    return false;
}

int T, a, b, c, p;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> p >> a >> b >> c;
        cout << (solve(p, a, b, c) ? "yes\n" : "no\n")  ;
    }
    return 0;
}
// 4 6 