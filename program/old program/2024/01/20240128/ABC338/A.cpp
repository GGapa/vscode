#include <bits/stdc++.h>
using namespace std;
string s;

void check() {
    if(!('A' <= s[0] && s[0] <= 'Z')) {
        cout << "No\n";
        return ;
    }
    for(int i = 1; i < s.length(); i++) {
        if(!('a' <= s[i] && s[i] <= 'z')) {
            cout << "No\n";
            return ;
        }
    }
    cout << "Yes";
    return ;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    check();
    return 0;
}\
//Capitalized? abc338_a