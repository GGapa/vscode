#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char a[100];
	int ls;
	cin>>a;
	for(int i = 0;i<100;i++)
	{
		if(a[i]=='\0')
		{
			ls=i;
		}
	}
	return 0;
}
