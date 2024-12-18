/*
#include <iostream> 
#include <iomanip>
using namespace std;

int main()
{
	int a[100];
	int i, n, c = 0, all=0;
	double pingjun = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < n; i++)
	{
		all = a[i] + all;
	}
	double ndouble = n,alldouble = all;
	pingjun = alldouble / ndouble;
	cout << "AVE=";
	printf("%.1f\n",pingjun);
	for (i = 0; i < n; i++)
	{
		if (a[i] > pingjun)
		{
			if (c < n-1)
			{
				cout << i+1 <<":"<< a[i] << " ";
			}
			else
			{
				cout << i+1 <<":"<< a[i] << endl;
			}
		}
	}
}
*/