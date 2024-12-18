//P5682 [CSP-J2019 江西] 次大值
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 2e5+100;
int n;
int a[maxn];
int main()
{
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int len = unique(a,a+n)-a;
	if(len<2)
	{
		cout<<-1<<endl;
	}
	else if(len==2)
	{
		cout<<a[0]%a[1]<<endl;
	}
	else
	{
		cout<<max(a[len-3]%a[len-1],a[len-1]%a[len-2])<<endl;
	}
	return 0;
}
