//B3633 集合运算 2
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;


int main()
{
    int lena,lenb,a[64],b[64],bucket[64]; 
    scanf("%d",&lena);
    if(lena!=0)for(int i = 1;i<=lena;i++)scanf("%d",&a[i]);
    scanf("%d",&lenb);
    if(lenb!=0)for(int i = 1;i<=lenb;i++)scanf("%d",&b[i]);
    cout<<lena<<endl;//(1)

    memset(bucket,0,sizeof(bucket));
    for(int i = 1;i<=lena;i++)bucket[a[i]]++;
    for(int i = 1;i<=lenb;i++)bucket[b[i]]++;
    for(int i = 0;i<64;i++)if(bucket[i]==2)printf("%d ",i);//(2)
    printf("\n");

    memset(bucket,0,sizeof(bucket));
    for(int i = 1;i<=lena;i++)bucket[a[i]]++;
    for(int i = 1;i<=lenb;i++)bucket[b[i]]++;
    for(int i = 0;i<64;i++)if(bucket[i]!=0)printf("%d ",i);//(3)
    printf("\n");

    memset(bucket,0,sizeof(bucket));
    for(int i = 1;i<=lena;i++)bucket[a[i]]++;
    for(int i = 0;i<64;i++)if(bucket[i]==0)printf("%d ",i);//(4)
    printf("\n");

    memset(bucket,0,sizeof(bucket));
    for(int i = 1;i<=lena;i++)bucket[a[i]]++;
    for(int i = 1;i<=lenb;i++)bucket[b[i]]++;
    bool success=false;
    for(int i = 0;i<64;i++)
    {
        if(bucket[i]==1){printf("0\n"),success=true;break;}
    }
    if(!success)printf("1\n");//(5)

    bool result=true;
    if(lena==0&&lenb!=0)printf("1\n");
    else if(lenb==0&&lena!=0)printf("0\n");
    else
    {
    for(int i = 1;i<=lena;i++)
    {
        success=false;
        for(int j = 1;j<=lenb;j++)
        {
            if(a[i]==b[j])success=true;
        }
        if(!success){printf("0\n"),result=false;break;}
    }
    if(result)printf("1\n");//(6)
    }

    memset(bucket,0,sizeof(bucket));
    for(int i = 1;i<=lena;i++)bucket[a[i]]++;
    if(bucket[0]>0)printf("1\n");
    else printf("0\n");//(7)

    return 0;
}