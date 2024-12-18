#include <iostream> 
using namespace std;

int a[200005];
int main() 
{
	int n,t,last,ans=0;
	cin>>n>>t;
	a[0]=0;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]-a[i-1]<=t&&i!=1)
		{
			ans+=(a[i]-a[i-1]);
		}
		else ans+=t;
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
