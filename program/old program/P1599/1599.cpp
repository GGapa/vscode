#include <iostream>
using namespace std;
int n, x, sum, ans, l;
bool bj;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        sum += x;
        ans += 1;
        if ((sum >= 0) && bj)
        {
            bj = 0;
            ans += (i - l) * 2;
        }
        if ((sum < 0) && !bj)
        {
            bj = 1;
            l = i;
        }
    }
    cout << ans << endl;
    return 0;
}