/*
P2842 纸币问题 1
https://www.luogu.com.cn/problem/P2842
*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
const int maxn = 1e3 + 5;
const int maxw = 1e4 + 5;
int n, w;
long long a[maxn] , f[maxw];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    f[0] = 0;
    for(int i = 1 ; i <= w; i++) {
        f[i] = INT_MAX;
        for(int j = 1; j <= n; j++) {
            if(i >= a[j]) f[i] = min(f[i], f[i - a[j]] + 1);
        }
    }
    cout << f[w] << endl;
}