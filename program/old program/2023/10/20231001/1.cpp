#include <iostream>
using namespace std;
typedef long long ll;

int n;
string a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> a;
    cout << a << endl;
    int t = n - a.size();
    ll ans = a.size() - 1;
    while(a.size() < n) 
        a.insert(0, ":");
    for(int i = 0; i < n; i++) if(a[i] == '∞') 
        a[i] = 58;
    ll now = 1;
    for(int i = n - 1; i >= 0; i--) {
        ans += now * (a[i] - '1');
        now *= 10;
    }
    cout << ans + t<< endl;
    return 0;   
}
/*
11  1
12  2
13  3
14  4
15  5
16  6
17  7
18  8
19  9
20  10
21  11
22  12
23  13
24  14
25  15
26  16
27  17
28  18
29  19
30  20
31  21

*/