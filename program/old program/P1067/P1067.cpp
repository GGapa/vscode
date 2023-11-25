//P1067 [NOIP2009 普及组] 多项式输出
#include <iostream> 
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	int n,input;
	bool first=true;
	scanf("%d",&n);
	if(n==0)
	{
		cout<<"1"<<endl;
		return 0;
	}
	for(int i = n+1;i>=1;i--)
	{
		scanf("%d",&input);
		if(input==0) continue;
		if(i==1)
		{
			if(first)
			{
				printf("x^%d",i-1);	
			}
			first=false;
			if(input>0)
			{
				printf("+%d",input);
			}
			else if(input<0)
			{
				printf("%d",input);
			}
		}
		else if(i==2)
		{
			if(first)
			{
				printf("x^%d",i-1);	
			}
			if(input>0)
			{
				if(input==1)
				{
					printf("+x");
				}
				else if(i==n)
				{
					printf("%dx",input);
				}
				else
				{
					printf("+%dx",input);
				}
			}
		
			else if(input<0)
			{
				if(input==-1)
				{
					printf("-x");
				}
				else
				{
					printf("%dx",input);
				}
			}
			first=false;
		}
		else if(i==n+1)
		{
			first=false;
			if(input!=1&&input!=-1)printf("%dx^%d",input,i-1);
			else if(input==1)printf("x^%d",i-1);
			else printf("-x^%d",i-1);
		}
		else if(input>0)
		{
			if(first)
			{
				printf("x^%d",i-1);	
			}
			first=false;
			if(input==1)
			{
				printf("+x^%d",i-1);
			}
			else if(i==n+1)
			{
				printf("%dx^%d",input,i-1);
			}
			else
			{
				printf("+%dx^%d",input,i-1);
			}
		}
		else if(input<0)
		{
			
			if(first)
			{
				printf("x^%d",i-1);	
			}
			first=false;
			if(input==-1)
			{
				printf("-x^%d",i-1);
			}
			else
			{
				printf("%dx^%d",input,i-1);
			}
		}
	}
	return 0;
}
