#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 20;

int T, n;
int a[30];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("AKIOI.in", "r", stdin);
    // freopen("AKIOI.out", "w", stdout);
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int it = 4;
        bool flag = true;
        for(int i = 4; i <= n; i++) {
            if(a[i - 1] > a[i]) {
                flag = false;
                break;
            }
            if(i == it) {
                it *= 2;
                i += 1;
            }
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}
//GGapa	A - Sorting with Twos	GNU C++14	Pretests passed (3)	46 ms	4 KB
