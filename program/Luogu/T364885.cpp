//T364885 小粉兔做麻辣兔头
//https://www.luogu.com.cn/problem/T364885?contestId=121028
#include <iostream>
#include <map>
using namespace std;

map<int,int> M;
int n;

int main() {
    for(int i = 1; i <= 6; i += 2) {
        M[i] = i + 1;
        M[i + 1] = i;
    }
    cin >> n;
    int ans = 0;
    for(int i = 1, op; i <= n; i++) {
        cin >> op;
        if(i == n) {
            ans += 21 - M[op];
        }
        else {
            ans += 21 - M[op] - op;
        }
    }
    cout << ans << endl;
    return 0;
}