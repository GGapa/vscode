//P1447 [NOI2010] 能量采集
#include<cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const long long maxn=100010;
long long n,m;
long long f[maxn],ans;
int main(){
    scanf("%d %d",&n,&m);
    if(n>m)swap(n,m);
    for(int i=n;i>0;--i)
	{
        f[i]=(n/i)*(m/i);
        
        for(int j=i<<1;j<=n;j+=i)
        {
			f[i]-=f[j];
		}
        ans+=((i<<1)-1)*f[i];
    }
    printf("%lld",ans);
	return 0;
}
