//B3715 分解质因子 2
//https://www.luogu.com.cn/problem/B3715
#include <iostream>
using namespace std;
#define int long long 
int T;
long long n;

signed main() {
    cin >> T;
    while (T--) {
        cin >> n;
        int m = n;
        for(int i = 2; 1ll * i * i <= n; i++) {
            while(m % i == 0) {
                m /= i;
                cout << i << ' ';
            }
        }
        if(m != 1)
        {
            cout << m ;
        }
        cout << endl;
    }
    return 0;
}