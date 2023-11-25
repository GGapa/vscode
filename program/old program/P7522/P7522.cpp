#include <iostream>
#include <limits.h>
#include <cmath>

using namespace std;

int main()
{
	long long Min=LLONG_MAX,Max=LLONG_MIN,temp,n;
	long long sum=0;
	cin>>n;
	if(n==1)
	{
        cin>>temp;
        cout<<temp<<endl;        
        return 0;
    }
	while(n--)
	{
		cin>>temp;
		sum+=abs(temp);
		Min=min(Min,temp);
		Max=max(Max,temp);
	}
	cout<<((long long)(sum-abs(Min)-abs(Max)+(Max-Min)));
	return 0;
}
