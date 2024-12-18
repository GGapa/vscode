// P9473 [yLOI2022] 西施江南
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 5e5;
int  prime[500010];
bool f[500010];
int a[maxn + 5];
map<int, int> mp;
#define gc getchar
inline int read()
{
    char c;
    int x=0,f=1;
    c=gc();
    while(!isdigit(c))
    {
        if(c=='-')f=-1;
        c=gc();
    }
    while(isdigit(c))
    {
        x=(x<<3)+(x<<1)+(c^48);
        c=gc();
    }
    return x*f;
}
#undef gc
int main()
{
    int index = 0;
   for(int i=2;i<=12295;i++)
    {
        if(f[i]==0) prime[++index]=i;
        for(int j=1;j<=index,i*prime[j]<=12295;j++)
        {
            f[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
    int T;
    cin>>T;
    while (T--)
    {
        int n;
        cin>>n;
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
        }
        if (n == 2)
        {
            cout << "Yes\n";
            continue;
        }
        mp.clear();
        bool flag = false;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            int tmp = a[i];
            for (int j = 1; j <= index; j++)
            {
                if (a[i] % prime[j] == 0)
                {
                    if (mp[prime[j]] == 1)
                    {
                        cout << "No\n";
                        flag = true;
                        break;
                    }
                    else
                    {
                        mp[prime[j]] = 1;
                    }
                }
                while (tmp % prime[j] == 0)
                    tmp /= prime[j];
            }
            if (tmp > 1)
            {
                if (mp[tmp] == 1 && !flag)
                {
                    cout << "No\n";
                    flag = 1;
                    break;
                }
                else
                    mp[tmp] = 1;
            }
            if (flag)
                break;
        }
        if (!flag)
            cout << "Yes\n";
    }
    return 0;
}