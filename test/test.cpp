#include<iostream>
#include<cmath>
using namespace std;
int n;
int a[205], b[205];
int m[205][205][205];
int c[205][205];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
		for (int j = 0; j < a[i]; j++)
		{
			for (int k = 0; k < b[i]; k++)
			{
				cin >> m[i][j][k];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a[i]; j++)
		{
			for (int k = 0; k < b[i]; k++)
			{
				bool jc = true;
				for (int i2 = 3; i2 < sqrt(m[i][j][k]); i2+=2)
				{
					if (m[i][j][k] % i2 == 0)
					{
						cout<<0<<" ";
						break;
					}
				}
				if(jc)
				{
					cout<<1<<" ";
				}
			}
			cout<<endl;
		}
		
	}
	return 0;
}