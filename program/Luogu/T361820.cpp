//T361820 前缀和
//https://www.luogu.com.cn/problem/T361820?contestId=122758
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int unsigned long long
int T;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--) {
        int n, x;
        cin >> n >> x;
        int ans = 0;
        int tmp = x;
        vector<int> a;
        a.push_back(x);
        while(tmp % 2 == 0) {
            tmp /= 2;
            a.push_back(tmp);
        }
        a.push_back(tmp);
        sort(a.begin(), a.end());
        for(int i = a.size(); i < n; i++) {
            a.push_back(a[i - 1] * 2);
        }
        cout << max(a[n - 1], x) << endl;
    }
    return 0;
}