/*
P1182 数列分段 Section II
https://www.luogu.com.cn/problem/P1182
*/
#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;

int n, m;
int l, r;
int a[maxn];

bool check(int x) {
    int sum = 1, val = 0;
    for(int i = 1; i <= n; i++) {
        if(val + a[i] > x) {
            sum++;
            val = a[i];
        }
        else val += a[i];
        if(sum > m) return sum > m;
    }
    return sum > m;
}//true -> x小了|||||x 大了

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }

    while(l < r) {
        int mid = (l + r) >> 1;
        if(check(mid)) {
            l = mid + 1;           
        }
        else {
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}