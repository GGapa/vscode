/**
 *    author:  tourist
 *    created: 23.02.2024 09:42:28
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> l(n), r(n);
        int beg = 0;
        while (beg < n)
        {
            int end = beg;
            while (end + 1 < n && a[end + 1] == a[end])
            {
                end += 1;
            }
            for (int i = beg; i <= end; i++)
            {
                l[i] = beg;
                r[i] = end;
            }
            beg = end + 1;
        }
        vector<int64_t> pref(n + 1);
        for (int i = 0; i < n; i++)
        {
            pref[i + 1] = pref[i] + a[i];
        }
        const int inf = int(1e9);
        vector<int> ans(n, inf);
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && a[i - 1] > a[i])
            {
                ans[i] = 1;
            }
            if (i < n - 1 && a[i + 1] > a[i])
            {
                ans[i] = 1;
            }
            { // left
                if (i > 0 && l[i - 1] > 0)
                {
                    int low = -1, high = l[i - 1] - 1;
                    while (low < high)
                    {
                        int mid = (low + high + 1) >> 1;
                        if (pref[i] - pref[mid] > a[i])
                        {
                            low = mid;
                        }
                        else
                        {
                            high = mid - 1;
                        }
                    }
                    if (low >= 0)
                    {
                        ans[i] = min(ans[i], i - low);
                    }
                }
            }
            { // right
                if (i < n - 1 && r[i + 1] < n - 1)
                {
                    int low = r[i + 1] + 1, high = n;
                    while (low < high)
                    {
                        int mid = (low + high) >> 1;
                        if (pref[mid + 1] - pref[i + 1] > a[i])
                        {
                            high = mid;
                        }
                        else
                        {
                            low = mid + 1;
                        }
                    }
                    if (low < n)
                    {
                        ans[i] = min(ans[i], low - i);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << (ans[i] == inf ? -1 : ans[i]) << " \n"[i == n - 1];
        }
    }
    return 0;
}