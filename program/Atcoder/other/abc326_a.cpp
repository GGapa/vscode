#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, y;
    cin >> x >> y;
    if(x - y >= 0 && x - y <= 3) {
        cout << "Yes\n";
        return 0;
    }
    else if(x - y <= 0 && x - y >= -2) {
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
    return 0;
}