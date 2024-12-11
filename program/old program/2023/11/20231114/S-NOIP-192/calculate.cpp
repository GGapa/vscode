#include <iostream>
#include <cmath>
using namespace std;
#define int long long

int read() {
    char c;
    int x = 0, f = 1;
    c = getchar();
    while(!isdigit(c)) {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(isdigit(c)) {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * f;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("calculate.in", "r", stdin);
    freopen("calculate.out", "w", stdout);
    int T = read()   ;
    while(T--) {
        int n = read(), d = read(), l = read(), r = read(), q = read();
        while(q--) {
            int x;
            cin >> x;
            x += l;
            int step = 0;
            if(x % n != 0 && step <= n + 5) {
                x = x * pow(d, ++step);
            }
            if(step <= n + 5)cout << step << "\n";
            else cout << -1 << "\n";
        }
    }
    return 0;
}