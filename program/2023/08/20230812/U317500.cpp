//U317500 drink
//https://www.luogu.com.cn/problem/U317500?contestId=123900

#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int main() {
    int n;
    cin >> n;
    int ans = 0;
    int left, right;
    left = right = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] == 1) {
            left = i;
            break;
        }
    }
    for(int i = n; i >= 0 ;i --) {
        if(a[i] == 1) {
            right = i;
            break;
        }
    }
    if(left != 0 && right != 0)cout << right - left + 1 << endl;
    else cout << 0 << endl;
    return 0;
}