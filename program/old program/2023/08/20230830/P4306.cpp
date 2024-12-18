/*
P4306 [JSOI2010] 连通数
https://www.luogu.com.cn/problem/P4306
*/
#include <iostream>
#include <bitset>
using namespace std;
const int maxn = 2000 + 5;

bitset<maxn> b[maxn];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        string Input;
        cin >> Input;
        for(int j = 0; j < n; j++) {
            b[i][j] = Input[j] - '0';
            if(i == j) 
                b[i][j] = 1;
        }
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            if(b[i][k]) {
                b[i] = b[i] | b[k];
            }
        }
    }
    int ans = 0 ;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans += b[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}