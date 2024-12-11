/*
https://www.luogu.com.cn/problem/P1627
P1627 [CQOI2009] 中位数
*/

#include <iostream>
#include <map>
using namespace std;
const int maxn = 100000 + 5;

int n, b;
int a[maxn];
int it;
map<int, int> mp;
int ind;
int  ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> b;
    for(int i = 1; i <= n; i++) {cin >> a[i], it = (a[i] == b) ? i : it;}
    ind = 0;
    for(int i = it; i <= n; i++) {
        if(a[i] != b) 
            ind += (a[i] > b) ? 1 : -1;
        mp[ind]++;
    }
    ind = 0;
    for(int i = it; i >= 1; i--) {
        if(a[i] != b) 
            ind += (a[i] > b) ? 1 : -1;
        //mp[ind]++;
        ans += mp[0 - ind];
    }
    cout << ans << "\n";
    return 0;
}