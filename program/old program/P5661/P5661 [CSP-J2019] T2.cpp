#include <iostream>
using namespace std;
struct pr
{
    int time, lasttime, spend;
    bool used = false;
} price[100005];
int main()
{
    int n, it = 0,l=0;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0)
        {
            ans += y;
            price[it].time = z;
            price[it].lasttime = z + 45;
            price[it].spend = y;
            it++;
        }
        bool ifuse = true;
        if (x == 1)
        {
            for (int j = l; j < it; j++)
            {
                if (price[j].used)
                    continue;
                if (price[j].lasttime < z)
                {
                    price[j].used = true;
                    l=j;
                    continue;
                }
                if (price[j].spend >= y)
                {
                    price[j].used = true;
                    ifuse = false;
                    break;
                }
            }
            if (ifuse==true)
                ans += y;
        }
    }
    cout << ans << endl;
    return 0;
}