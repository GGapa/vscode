// LIS
#include <iostream> 
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 100000+10;
int a[maxn],s[maxn],it=0;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	s[++it]=a[1];
	for(int i = 2;i<=n;i++)
	{
		if(s[it]<a[i])s[++it]=a[i];
		else
		{
			int temp=lower_bound(s+1,s+1+it,a[i])-s;
			s[temp]=a[i];
		}
	}
	printf("%d",it) ;
	return 0;
}
