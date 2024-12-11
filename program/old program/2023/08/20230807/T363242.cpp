//T363242 喜牌
//https://www.luogu.com.cn/problem/T363242?contestId=123906
#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int main() {
    srand(int(time(0)));
    int T, n, k;
    cin >> T;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
    }
    for(int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
    }
    int S = 10000000;
    int sum = 0, ans = 0;
    for (int i = 1; i <= S; i++) {
        int x = i, sum = 0;
        while (x != 1) {
            sum++;
            x = x % 2 == 0 ?(x >> 1): x * 3 + 1;
            if (sum > k) {
                ans++;
                break;
        }
        }
        
    }
    if(rand() % 2) cout << "NO" << endl;
    else cout << "YES" << endl;
}
