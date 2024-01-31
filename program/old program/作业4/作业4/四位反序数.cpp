/*
#include <iostream>
using namespace std;

int main()
{
	int i,n,q,m,num=0;
	for (i = 1000; i <= 9999; i++)
	{
		n = i*9;
		num = 0; 
		while (n != 0)
		{
			m = n % 10;
			n = n / 10;
			num = 10 *num + m;
		}
		if (num == i)
		{
			cout << i << endl;
			return 0;
		}
	}
}
*/