//X-factor Chains
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1024*1024+10;
bool isp[maxn];
vector<int> prime;
void getprime(int n)
{
    memset(isp, 1, sizeof isp);
    for(int i = 2; i <= n; ++i)
    {
        if(isp[i])
            prime.push_back(i);
        for(int j = 0; i * prime[j] <= n; ++j)
        {
            isp[i * prime[j]] = 0;
            if(i % prime[j] == 0)
                break;
        }
    }
}
int C(int n, int k)
{
    int ans = 1;
    for(int i = 1, j = n; i <= k; ++i, --j)
        ans = ans * j / i;
    return ans;
}
vector<int> cnt;
int getnum(int n)
{
    cnt.clear();
    int sum = 0;
    for(int i = 0; n != 1; ++i)
    {
        if(n % prime[i] == 0)
        {
            cnt.push_back(1);
            n /= prime[i];
            while(n % prime[i] == 0)
            {
                cnt.back()++;
                n /= prime[i];
            }
            sum += cnt.back();
        }
    }
    return sum;
}
int main()
{
    getprime(1024*1024);
    int X;   
    while(scanf("%d", &X) != EOF)
    {
        int n = getnum(X);
        int ans1 = n, ans2 = 1;
        int len = cnt.size();
        for(int i = 0; i < len-1; ++i)
        {
            ans2 *= C(n, cnt[i]);
            n -= cnt[i];
        }
        cout << ans1 << ' ' << ans2 << endl;
    }
    return 0;
}