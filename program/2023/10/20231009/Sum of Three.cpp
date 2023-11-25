#include <iostream>
using namespace std;

int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        if(n <= 6) {
            cout << "NO\n";
            continue;
        }
        if(n % 3 != 0 && n - 3 != 2) cout << "YES\n1 2 " << n - 3 << "\n";
        else if(n % 3 == 0 && n - 5 != 4) cout << "YES\n1 4 " << n - 5 << "\n";
        else cout <<"NO\n";
    }
}