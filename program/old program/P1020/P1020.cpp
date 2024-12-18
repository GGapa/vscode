//P1020 [NOIP1999 普及组] 导弹拦截
#include <iostream>
#include <cstdio>
#include <limits.h>
#include <cstring>
using namespace std;
int fire[100005],n=0,dp[100005],mans=0,kill[100005],it=1;
int main()
{
    dp[0]=INT_MAX;
    while(~scanf("%d",&fire[++n]))if(fire[n]==0)break;
    n-=1;
    for(int i = 1;i<=n;i++)
    {
        int left=0,right=n+1;
        while(right-left>1)
        {
            int middle=left+(right-left)/2;
            if(dp[middle]>=fire[i])left=middle;
            else right=middle;
        }
        int tmp=left+1;
        if(tmp>mans)mans=tmp;dp[tmp]=fire[i];
        /*
        dp[i]=1;
        for(int j = 1;j<=i-1;j++)
        {
            if(fire[j]>=fire[i])dp[i]=max(dp[i],dp[j]+1);
        }
        mans=max(mans,dp[i]);
        */
    }
    cout<<mans<<endl;
    mans=0;
    memset(dp,9,sizeof(dp));
    for(int i = 1;i<=n;i++)
    {
        int left=0,right=n+1;
        while(right-left>1)
        {
            int middle=left+(right-left)/2;
            if(dp[middle]<fire[i])left=middle;
            else right=middle;
        }
        int tmp=left+1;
        if(tmp>mans)mans=tmp;dp[tmp]=fire[i];
    }
    /*
    for(int i = 1;i<=n;i++)
    {
        int tmp=INT_MAX,tmp2;
        for(int j = 1;j<it;j++)
        {
            if(kill[j]>=fire[i])
            {
                if(tmp>kill[j])
                    tmp2=j,tmp=kill[j];
            }
        }
        
        if (tmp==INT_MAX)kill[it++]=fire[i];
        else kill[tmp2]=fire[i];
    }
    */
    cout<<mans<<endl;
    return 0;
}