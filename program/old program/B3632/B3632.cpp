//B3632 集合运算 1
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
    cout<<lena<<endl;
    memset(bucket,0,sizeof(bucket));
    for(int i = 1;i<=lena;i++)bucket[a[i]]++;
    for(int i = 1;i<=lenb;i++)bucket[b[i]]++;
    for(int i = 0;i<64;i++)if(bucket[i]==2)printf("%d ",i);
    printf("\n");
    memset(bucket,0,sizeof(bucket));
    for(int i = 1;i<=lena;i++)bucket[a[i]]++;
    for(int i = 1;i<=lenb;i++)bucket[b[i]]++;
    for(int i = 0;i<64;i++)if(bucket[i]!=0)printf("%d ",i);
    printf("\n");
    return 0;
}