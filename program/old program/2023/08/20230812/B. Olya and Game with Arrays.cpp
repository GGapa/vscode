//B. Olya and Game with Arrays
//https://codeforces.com/contest/1859/problem/B
#include <iostream>
#include <limits.h>
#include <cstring>
using namespace std;
typedef long long ll;
#define int long long
int T;
int n;
int Minnum[25000], Min2num[25000], MMMinval, MMMinindex, MMMin2val, MMMin2index;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> n;
        MMMinval = LLONG_MAX;
        MMMinindex = LLONG_MAX;
        MMMin2val = LLONG_MAX;
        MMMin2index = LLONG_MAX;
        for(int i = 1; i <= n; i++) {
            int m;
            cin >> m;
            Minnum[i] = LLONG_MAX;
            Min2num[i] = LLONG_MAX;
            for(int j = 1; j <= m; j++) {
                int Input;
                cin >> Input;
                if(Input < Minnum[i]) {
                    Min2num[i] = Minnum[i];    
                    Minnum[i] = Input;
                }
                if(Input < Min2num[i] && Input != Minnum[i]) {
                    Min2num[i] = Input;
                }
            }
            if(Minnum[i] < MMMinval) {
                MMMinval = Minnum[i];
                MMMinindex = i;
            }
            if(Min2num[i] < MMMin2val) {
                MMMin2val = Min2num[i];
                MMMin2index = i;
            }
            if(Min2num[i] == LLONG_MAX) {
                Min2num[i] = Minnum[i];
            }
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            if(i != MMMin2index) {
                ans += Min2num[i];
            }
            else ans += MMMinval;
        }
        cout << ans << endl;
    }
    return 0;
}