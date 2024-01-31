#include <bits/stdc++.h>
using namespace std;

int n, k;

void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) 
        for(char j = 'a'; j < 'a'+ k; j++) cout << j;
    cout << '\n';
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--)solve();
    return 0;
}