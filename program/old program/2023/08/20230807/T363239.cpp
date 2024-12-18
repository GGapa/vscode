//T363239 双端队列
//https://www.luogu.com.cn/problem/T363239?contestId=123906
#include <iostream>
#include <vector>
using namespace std;
int T, n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> n;
        vector<int> a(n);
        for(auto &i : a) cin >> i;
        bool tag = true, ans = true;
        int it = 0;
        while(a[it] > a[it + 1]) it++;
        while(a[it] < a[it + 1]) it++;
        if(it >= n - 1) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}