#include <iostream>
#include <cmath>
using namespace std;

int n, l, r;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l >> r;
    for(int i = 1, t; i <= n; i++) {
        cin >> t;
        if(l <= t && t <= r) cout << t << " ";
        else if(t < l) cout << l <<  " ";
        else cout << r << " ";
    }
    return 0;
}