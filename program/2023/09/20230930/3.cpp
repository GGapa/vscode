#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int mod = 1e9 + 7;

#define int long long 

int n;  
int mp[200][200];

int f(int x, int y) {
    if (x == 0) return 0;
    if (x == 1) return (y > 0 && y <= n / 2) ? 1 : 0;
    int tmp = 0;
    if(mp[x][y] != 0) 
        return mp[x][y];
        for (int i = 1; i <= min(y, n / 2); i++) {
            tmp =  (tmp + f(x - 1, y - i) % mod) % mod;
        }
        mp[x][y] = tmp;
        return tmp;
}

signed main() {
    int t;  
    cin >> t;
    while (t--) {
        cin >> n;
        cout << f(n, 2 * n - 1) % mod << endl;
    }

    return 0;
}
