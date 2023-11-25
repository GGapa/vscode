/**
 * @Problem      : UVA12100
 * @URL          : https://www.luogu.com.cn/problem/UVA12100
 * @Author       : GGapa
 * @Date         : 2023-11-17 11:18:30
 * @LastEditTime : 2023-11-17 15:09:49
**/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1005;
#define _for(i, a, b) for(int i = (a); i <= (b); i++)


int T;
int n, top;
int lev[11] ;
pii a[maxn * maxn];

bool check(int x) {
    _for(i, x + 1, 9) if(lev[i]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout):
    cin >> T;
    while(T--) {
        memset(lev, 0, sizeof(lev));
        cin >> n >> top;
        int it = 1, bk = n, out = 1;
        for(int i = 1; i <= n; i++) cin >> a[i].first, lev[a[i].first]++, a[i].second = i;
        while(it <= bk) {
        if(check(a[it].first)) {
            if(a[it].second == top + 1) {
                cout << out << '\n';
                break   ;
            }
            out++;
            lev[a[it++].first]--;
        }
        else {
            a[++bk] = a[it++];
        }
        }
    }
    return 0;
}
//AC 100pts