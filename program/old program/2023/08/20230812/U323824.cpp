//U323824 color
//https://www.luogu.com.cn/problem/U323824?contestId=123900
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int sum = a + b + c + d + e;
    if(sum <= 99) cout << "Gray" << endl;
    else if (sum <= 119) cout << "Blue" << endl;
    else if (sum <= 169) cout << "Green" << endl;
    else if (sum <= 229) cout << "Orange" << endl;
    else cout << "Red" << endl;
    return 0;
}
