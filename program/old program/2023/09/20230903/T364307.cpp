/*
T364307 「Daily OI Round 1」Block
https://www.luogu.com.cn/problem/T364307?contestId=123625
*/

#include <iostream>
using namespace std;
const int mod = 1e9 + 7;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    unsigned long long sum;
    for(int i = 1; i <= n; i++) {
        sum = (sum + i) % mod;
    }
    cout << n << endl;
    return 0;
}