//P1142 轰炸
//(x1-x2)(y1-y3)=(y1-y2)(x1-x3)
#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 701

int x[701],y[701];
int n;
int ans=0,mans=-1;
int main()
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
    }
    for(int i = 1;i<=n;i++)//1
    {
        for(int j = i+1;j<=n;j++)//2
        {
            for(int q = 1;q<=n;q++)//3
            {
                if(q==i||q==j)continue;
                if( ((x[i]-x[j])*(y[i]-y[q])) == ((y[i]-y[j])*(x[i]-x[q])) )ans++;
                mans=max(mans,ans);
            }
            ans=0;
        }
    }
    cout<<mans+2<<endl;
    return 0;
}