/*
Open Credit System
https://www.luogu.com.cn/problem/UVA11078
*/

#include <iostream>
#include <limits.h>
using namespace std;

int n;
int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> n;
        int mmax = INT_MIN, ans = INT_MIN;
        int tmp;
        cin >> tmp;
        mmax = tmp;
        for(int i = 1; i <= n; i++) {
            int Input;
            cin >> Input;
            ans = max(ans, mmax - Input);
            mmax = max(Input, mmax);
        }
        cout << ans << endl;
    }
    return 0;
}

