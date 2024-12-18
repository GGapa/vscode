// n^2 TLE

#include <iostream> 
using namespace std;
const int maxn = 100000+10;
int n,a[maxn],dp[maxn],ans=0;
int main()
{
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<i;j++)
		{
			if(a[j]<a[i])dp[i]=max(dp[i],dp[j]);
		}
		dp[i]++;
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
