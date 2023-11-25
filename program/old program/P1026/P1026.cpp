// P1026 [NOIP2001 提高组] 统计单词个数
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int p, k, s;
string a = "", words[10];
int dp[205][205], sum[205][205];
inline bool check(int left, int right)
{
    string tmp = a.substr(left, right - left + 1);
    for (int i = 1; i <= s; i++)
    {
        if (tmp.find(words[i]) == 0)
            return true;
    }
    return false;
}
int main()
{
    a += '0';
    scanf("%d%d", &p, &k);
    for (int i = 1; i <= p; i++)
    {
        string tmp;
        cin >> tmp;
        a += tmp;
    }
    scanf("%d", &s);
    int len = a.length() - 1;
    for (int i = 1; i <= s; i++)
        cin >> words[i];
    for (int i = len; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {

            sum[j][i] = sum[j + 1][i];
            if (check(j, i))
                sum[j][i]++;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++)
    {
        dp[i][i] = dp[i - 1][i - 1] + sum[i][i];
    }
    for (int i = 1; i <= len; i++)
    {
        dp[i][1] = sum[1][i];
    }
    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= k && j < i; j++)
        {
            for (int q = j; q < i; q++)
            {
                dp[i][j] = max(dp[i][j], dp[q][j - 1] + sum[q + 1][i]);
            }
        }
    }
    cout << dp[len][k];
    return 0;
}