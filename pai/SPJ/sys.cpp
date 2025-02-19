#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    system("g++ data.cpp -o data.exe");
    system("g++ user.cpp -o user -O2 -std=c++14 -Wl,--stack=512000000");
    system("g++ checker.cpp -o checker.exe");
    // system("pause");

    for(int cnt = 1; ; cnt++) {
        system("data.exe");
        system("user.exe");
        system("checker.exe");
        if(system("fc checker.out ok.txt")) exit(0);
        cerr << cnt << '\n';
    }

    return 0;
}