#include <iostream>
using namespace std;

int main()
{
	int a,b,c=0;
	cin>>a;
	for (int i = 1;i<=a;i++)
	{
		if(i==(i*i)%10||i==(i*i)%100||i==(i*i)%1000||i==(i*i)%1000) c++;
		
	}
	cout <<c<<endl;
	return 0;
}
