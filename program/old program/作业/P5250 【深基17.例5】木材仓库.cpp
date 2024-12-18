/*
#include <iostream>
#include <cmath>
#include <set>
using namespace std;
multiset <int> a;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        if (x == 1)
        {
            auto it = a.find(y);
            if (it != a.end())
            {
                if (*it == y)
                    cout << "Already Exist" << endl;
                else
                    a.insert(y);
            }
            else
                a.insert(y);
        }
        if (x == 2)
        {
            if (a.empty())
                cout << "Empty" << endl;
            else if (a.find(y) != a.end())
            {
                cout << (y) << endl;
                a.erase(y);
            }
            else
            {
                auto it1 = a.lower_bound(y);
                auto it2 = it1;
                if (it1 != a.begin())
                    it1--;

                if (it1 != a.end())
                {
                    if (abs( * it1 - y) == abs( * it2 - y))
                    {
                        cout << (min(*it1, *it2)) << endl;
                        a.erase(min(*it1, *it2));
                    }
                    else if (abs( * it1 - y) > abs( * it2 - y))
                    {
                        cout << (*it2) << endl;
                        a.erase(*it2);
                    }
                    else
                    {
                        cout << (*it1) << endl;
                        (a.erase(*it1));
                    }
                }
            }
        }
    }
    return 0;
}
*/