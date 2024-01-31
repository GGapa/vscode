#include <bits/stdc++.h>
using namespace std;

string s;
int a[30];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for(auto c : s) {
        a[c -'a']++;
    }
    int it = 0;
    for(int i = 0; i < 26; i++) {
        if(a[i] > a[it]) it = i;
    }
    cout << char(it + 'a');
    return 0;
}