//Tower of Hanoi 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void work(int n, int a, int b, int c) {
    if(n == 1) {
        cout << a << " " << c << '\n';
        return ;
    }
    return work(n - 1, a, c, b), work(1, a, b, c), work(n - 1, b, a, c);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << (1 << n)  - 1 << '\n';
    work(n, 1, 2, 3);
    return 0;
}