//P6033 [NOIP2004 提高组] 合并果子 加强版
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
priority_queue<long long, vector <long long>,greater<long long> >a;

int main()
{
	long long n;
	long long ans = 0;
	scanf("%lld",&n);
	for (int i = 0; i < n; i++)
	{
		long long l;
		scanf("%lld",&l);
		a.push(l);
	}
	while (a.size() >= 2)
	{
		long long temp1 = a.top();
		a.pop();
		long long temp2 = a.top();
		a.pop();
		ans = ans + temp1 + temp2;
		a.push(temp1+temp2);
	}  
    printf("%lld",ans);
	return 0;
}