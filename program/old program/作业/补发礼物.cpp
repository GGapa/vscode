/*
#include <iostream>
using namespace std;

int main()
{
	int n,i,j,biaoji=1;
	cin >> n;
	int a[100], b[100];
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] <= 0)
		{
			a[i] = 1;
		}
		for (j = a[i]; j < a[i]+13; j++)
		{
			if (j % 4 == 0&&j>=10)
			{
				b[i] = j;
				break;
			}
				
		}
	}
	while (biaoji == 1)
	{
		biaoji = 0;
		for (i = 0; i < n-1; i++)
		{
			if (b[i] < b[i+1])
			{
				int l = b[i];
				b[i] = b[i + 1];
				b[i + 1] = l;
				biaoji = 1;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (i != 0)
		{
			printf(" ");
		}
		printf("%d",b[i]);
		
	}
	return 0;
}
*/