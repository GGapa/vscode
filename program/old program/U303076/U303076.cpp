// U303076 浴眼盯真
// https://www.luogu.com.cn/contest/38434

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        string a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a[0] == 'y' && b[0] == 'y' && c == "ding" && d == "zhen")
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}