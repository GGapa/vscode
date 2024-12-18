//P1970 [NOIP2013 提高组] 花匠
#include <iostream>
using namespace std;
int n,h[10000006],ans=0;
bool bj=0;
int main()
{
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>h[i];
	}
	if(h[2]>=h[1]) bj=1;
	for(int i = 1;i<=n;i++)
	{
		if(bj==0&&i==n) {ans++;break;}
        if(bj==1&&h[i+1]<h[i]) 
			{ans++;bj=0;continue;}
        if(bj==0&&h[i+1]>h[i]) 
			{ans++;bj=1;continue;}
	}
	cout<<ans+1<<endl;
	return 0;
}
