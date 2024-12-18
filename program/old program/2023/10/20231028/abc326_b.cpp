#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = n; i <= 999; i++) {
        int a = i / 100, b = i % 100 / 10, c = i % 10;
        if(a * b == c) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}