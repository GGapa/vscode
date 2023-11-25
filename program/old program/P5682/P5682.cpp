//P5682 [CSP-J2019 江西] 次大值
#include <iostream>
#include <cstdio> 
#include <set>
using namespace std;
const int maxn = 2e5+10;
set<int> m;
int a[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(j==i)continue;
			m.insert(a[i]%a[j]);
		}
	}
	if(m.size()>=2)
	{
		set<int>::iterator ans=m.end();
		ans--;
		ans--;
		printf("%d",*ans);
	}
	else
	{
		cout<<-1<<endl;
	}
	return 0;
}
