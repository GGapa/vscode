// T356637 洛谷网红的粉丝们 (fans)
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e6 + 5;
#define ll long long
#define int ll
int A[maxn], B[maxn];
int n;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 1; i <= n; i++)
        cin >> B[i];
    sort(A + 1, A + 1 + n);
    sort(B + 1, B + 1 + n);
    int ans1 = 0;
    int ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = A[i];
        int left = lower_bound(B + 1, B + 1 + n, tmp) - B;
        int right = upper_bound(B + 1, B + 1 + n, tmp) - B;
        ans1 += left - 1;
        ans2 += n - right + 1;
    }
    cout << ans1 << "\n" << ans2 <<"\n" <<endl;
    return 0;
}