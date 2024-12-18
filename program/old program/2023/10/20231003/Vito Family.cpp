/*
Vito's Family
https://vjudge.csgrandeur.cn/contest/584210#problem/B
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &i : a) 
            cin >> i;
        sort(a.begin(), a.end());
        int mid = a.size() >> 1;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += abs(a[mid] - a[i]);
        }   
        cout << ans << endl;
    }
    return 0;
}