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
    cout << ans + 1 << endl;
    return 0;   
}