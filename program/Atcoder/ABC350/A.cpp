#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    if(s.size() < 6 || s.substr(0, 3) != "ABC" || stoi(s.substr(3, 3)) > 349 || stoi(s.substr(3, 3)) == 316 || stoi(s.substr(3, 3)) < 1) 
        cout << "No\n";
    else 
        cout << "Yes\n";
    return 0;
}