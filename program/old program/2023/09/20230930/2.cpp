/*
author:GGapa
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;

int n, m;
string a;
int op[maxn];
int mp[30][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> a;
    a.insert(0, " ");
    for(int i = 1; i < a.size(); i++) {
        mp[a[i] - 'a'][i]++;
        for(char j = 'a'; j <= 'z'; j++) {
            mp[j - 'a'][i] += mp[j - 'a'][i - 1];
        }
    }
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int x, y;
            cin >> x >> y;
            int out = 0;
            for(int i = 'a'; i <= 'z'; i++) {
                //cout << mp[i][y] << " " << mp[i][x - 1] << endl;
                if((mp[i - 'a'][y] - mp[i - 'a'][x - 1]) % 2 == 1) out++;
            }
            cout << out << endl;
        }
        if(op == 2) {
            int x;
            char y;
            cin >> x >> y;
            for(int i = x; i <= n; i++) {
                mp[y - 'a'][i]++;
                mp[a[x] - 'a'][i]--;
            }
        }
    }
    return 0;
}