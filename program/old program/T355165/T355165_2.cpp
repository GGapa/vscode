#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<int> dp(n + 1, 0);

    
    dp[n] = 1;

    for (int i = n - 1; i >= 1; --i)
    {
        int j = i + a[i] + 1;
        if (j <= n)
        {
            dp[i] = max(dp[i + 1], dp[j] + 1);
        }
        else
        {
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[1] << endl;

    return 0;
}
