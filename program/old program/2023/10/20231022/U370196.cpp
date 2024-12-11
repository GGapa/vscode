#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long ans = 2;
    for(int i = 2; i <= n; i++) ans *= 2;
    cout << ans - 1 << "\n" ;
    return 0;
}