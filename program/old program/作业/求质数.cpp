/*
#include <iostream>
using namespace std;

int main()
{
	int a[100],i=0,q,all = 0,b=1,j,biaoji=1,count=0;
	while (b != 0) {
		cin >> b;
		a[count]=b;
		count++;
	}
	for (i = 0; i < count-1; i++)
	{
		for (j = 2; j <= a[i]; j++)
		{
			biaoji = 1;
			for (q = 2; q < j; q++) {
				if (j % q == 0)
				{
					biaoji = 0;
					break;
				}
				
			}
			if (biaoji == 1) all++;
			
			
		}
		cout << all << endl;
		all = 0;
		if (a[i] == 0) break;
	}
	return 0;
*/