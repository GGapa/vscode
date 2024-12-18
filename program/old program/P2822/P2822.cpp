//P2822 [NOIP2016 提高组] 组合数问题
#include <iostream>
#include <cstdio>
using namespace std;
long long san[2001][2001],sum[2001][2001];
unsigned
int t,k;

inline void start()
{
    for(int i = 0;i<=2000;i++)
    {
        san[i][0]=1;
    }
    for(int i = 1;i<=2000;i++)
    {
        for(int j = 1;j<=i;j++)
        {
            san[i][j]=(san[i-1][j]+san[i-1][j-1])%k;
        }
    }
}
inline void prepar()
{
    for(int i = 1;i<=2000;i++)
    {
        for(int j = 1;j<=i;j++)
        {
            if(san[i][j]==0)
            {
                sum[i][j]++;
            }
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];          
        }
        for(int j = i+1;j<=2000;j++)
        {
            sum[i][j]=sum[i][i];
        }
    }
}
int main()
{
    scanf("%d%d",&t,&k);
    start();
    prepar();
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        cout<<sum[n][m]<<endl;
    }
    return 0;
}