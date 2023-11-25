// B3667 求区间所有后缀最大值的位置
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
using namespace std;

#define ull unsigned long long
#define int ull
ull n, k;
ull a[10000005];
deque<ull> q;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (q.size() && q.front() + k - 1 < i)
            q.pop_front();
        while (q.size() && (a[i] >= a[q.back()]))
        {
            q.pop_back();
        }
        q.push_back(i);
        if (i >= k)
            cout << q.size() << endl;
        
    }
    return 0;
}