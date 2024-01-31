#include <iostream>
using namespace std;

int main()
{
	int n,i,q,ji=1,all=0;
	cin >>n;
	for(i=1;i<=n;i++)
	{
		for(q=1;q<=i;q++)
		{
			ji=ji*q;
		}
		
		if(i%2==0)all = all-ji;
		else all=all+ji;
		ji = 1;
	}
	cout<<all<<endl;
	return 0;
}
