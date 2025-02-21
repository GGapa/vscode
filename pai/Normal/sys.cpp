#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // system("g++ data.cpp -o data.exe");
    // system("g++ user.cpp -o user -O2 -std=c++14 -Wl,--stack=512000000");
    // system("g++ baoli.cpp -o baoli.exe -Ofast");

    for(int cnt = 0; ; ) {
        system("data.exe");
        system("baoli.exe");
        system("user.exe");
        cerr << 1 << '\n';
        if(system("fc data.out user.out")) exit(0);
        cerr << ++cnt << '\n';
    }
    return 0;
}