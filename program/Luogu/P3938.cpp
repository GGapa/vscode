/*
P3938 斐波那契
https://www.luogu.com.cn/problem/P3938
*/

#include <iostream>
#include <algorithm>
using namespace std;


long long fab[63];

void _find(long long a, long long b) {
    if(a < b) swap(a, b);
    if(a == b) {cout << a << endl; return;}
    int tmp = lower_bound(fab + 1, fab + 63, a) - fab;
    _find(b, a - fab[tmp-1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    fab[1] = fab[2] = 1;
    for(int i = 3; i <= 61; i++) {
        fab[i] += fab[i - 1] + fab[i - 2];
    }
    for(int i = 1; i <= n; i++) {
        long long a, b;
        cin >> a >> b;
        _find(a, b);
    }

    return 0;

}