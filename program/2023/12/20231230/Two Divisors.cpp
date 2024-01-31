#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
 
int T;
int a, b;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    rep(_, 1, T) {
        cin >> a >> b;
        int gcd = __gcd(a, b);
        a /= gcd, b /= gcd;
        if(a == 1) a = b;
        cout << a * b * gcd << '\n';

    }
    return 0;
}