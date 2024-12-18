//P1142 轰炸
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int point[3][701],n;//1=x||2=y
int it=1;//k的指针
int ans=0,mans=-1;
float k[701][701];//y=kx+b
//float b[490001];
int main()
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d%d",&point[1][i],&point[2][i]);
    }
    for(int i = 1;i<=n;i++)
    {
            for(int j = i+1;j<=n;j++)
            {
                if(j==i)continue;
                k[i][j]=(double)(point[2][i]-point[2][j])/(double)(point[1][i]-point[1][j]);//k=(y1-y2)/(x1-x2)
                //b[it]=(double)point[2][i]-(double)k[it]*point[1][i];//计算解析式
                //cout<<k[it]<<" "<<b[it]<<endl;
                //it++;
            }
    }
    //sort(k+1,k+it);
    for(int i = 1;i<=n;i++)
    {
        sort(k[i]+1,k[i]+1+n);
        int ls=0;
        ans=-1;
        for(int j = i+1;j<n;j++)
        {
            if(i==j)continue;
            if(k[i][j]==k[i][j+1])
                ls++;
            else 
                ls=0;
            ans=max(ans,ls);
        }
        //ans=0;
        mans=max(ans,mans);
    }
    cout<<mans+2<<endl;
    return 0;
}

