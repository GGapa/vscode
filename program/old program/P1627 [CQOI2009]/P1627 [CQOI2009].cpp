// P1627 [CQOI2009] 中位数（未解决）
#include <iostream>
using namespace std;

int main()
{
    int n, b, a[100005];
    long long ans = 1;
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == b)
        {
            int l = i - 1;
            int r = i + 1;
            int lnum = 0, rnum = 0;
            while (l > 0 && r <= n)
            {
                if (lnum == rnum)
                    ans++;
                if (a[l] < b)
                    lnum++;
                else if (a[l] > b)
                    rnum++;
                if (a[r] < b)
                    lnum++;
                else if (a[r] > b)
                    rnum++;
                l--;
                r++;
            }
        }
    }
    cout << ans << endl;
}