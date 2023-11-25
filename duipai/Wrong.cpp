#include <bits/stdc++.h>
using namespace std;

namespace STD
{
    void STD()
    {
        int n;
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin >> n;
        vector<int> a(n), b, c;
        for (auto &i : a)
        {
            cin >> i;
        }
        b.push_back(a[0]);
        c.push_back(a[1]);
        for (int i = 2; i < n; i++)
        {
            if ((b.empty() || b.size() < c.size() || a[i] == c.back()) && a[i] != b.back())
            {
                b.push_back(a[i]);
            }
            else if (c.empty() || a[i] != c.back())
            {
                c.push_back(a[i]);
            }
            else
            {
                int tmp = 0;
                tmp++;
            }
        }
        cout << b.size() + c.size() << endl;
    }
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("Wrong.out", "w", stdout);
    STD::STD();
    return 0;
}
