// P6784 「EZEC-3」造房子
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long a, b, c, floor = 0;
    cin >> a >> b >> c;
    long long x = abs(a - b);
    if (a < b)
        a += min(x, c);
    else if (a > b)
        b += min(x, c);
    c -= min(x, c);
    if (c)
    {
        a += c / 2;
        b += c / 2;
    }
    while (a - floor - 1 >= 0 && b - floor - 1 >= 0)
    {
        floor++;
        a -= floor;
        b -= floor;
    }
    cout << floor << endl;
    return 0;
}