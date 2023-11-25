#include <iostream> 
#include <algorithm>
#include <cstdio>
using namespace std;
int a[5];
char opt[5]= {' ','+','-','*','/'};
int js(int x, int t, int y)
{
	if (t == 1)return x + y;
	if (t == 2)return max(x,y)-min(x,y);
	if (t == 3)return x * y;
	if (t == 4)
	{
		if (y==0 || x<y || x%y!=0) return -999999;
		return x / y;
	}
}

char fh(int i)
{
	if (i == 1)return '+';
	if (i == 2)return '-';
	if (i == 3)return '*';
	if (i == 4)return '/';
}
void print(int a,int b,int c,int d,int e,int f,int k1,int k2,int k3)
{
  	printf("%d%c%d=%d\n",max(a,b),opt[k1],min(a,b),js(max(a,b),k1,min(a,b)));
 	printf("%d%c%d=%d\n",max(c,d),opt[k2],min(c,d),js(max(c,d),k2,min(c,d)));
 	printf("%d%c%d=%d\n",max(e,f),opt[k3],min(e,f),js(max(e,f),k3,min(e,f)));
 	exit(0);
}

int main()
{
	scanf("%d %d %d %d",&a[1],&a[2],&a[3],&a[4]);
	sort(a+1,a+5) ;
	do
	{

		for(int i = 1;i<=4;i++)
		{
			for(int j = 1;j<=4;j++)
			{
				for(int q = 1;q<=4;q++)
				{
					if (js(js(js(a[1],i,a[2]),j,a[3]),q,a[4])==24)
					{
           				print(a[1],a[2],js(a[1],i,a[2]),a[3],js(js(a[1],i,a[2]),j,a[3]),a[4],i,j,q);
           			}
          			else if (js(js(a[1],i,a[2]),q,js(a[3],j,a[4])) == 24)
          			{
            			print(a[1],a[2],a[3],a[4],js(a[1],i,a[2]),js(a[3],j,a[4]),i,j,q);
            		}
				}
			}
		}
	}while(next_permutation(a+1,a+5));
	
	printf("No answer!");
	return 0;
}
