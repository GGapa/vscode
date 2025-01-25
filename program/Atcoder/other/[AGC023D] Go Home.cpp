#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long s;
    cin >> n >> s;
    vector<long long> x(n);
    vector<long long> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> p[i];
    }
    vector<long long> route;
    long long ans = 0;
    int i = 0, j = n - 1;
    while (true)
    {
        if (x[j] < s)
        {
            route.push_back(x[i]);
            break;
        }
        if (x[i] > s)
        {
            route.push_back(x[j]);
            break;
        }
        if (p[i] >= p[j])
        {
            route.push_back(x[j]);
            p[i] += p[j];
            j--;
        }
        else
        {
            route.push_back(x[i]);
            p[j] += p[i];
            i++;
        }
    }
    for (int ii = (int)route.size() - 1; ii >= 0; ii--)
    {
        ans += abs(s - route[ii]);
        s = route[ii];
    }
    cout << ans << '\n';
    return 0;
}
