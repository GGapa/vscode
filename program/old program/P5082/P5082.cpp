#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long a,b,c;
    a=b=c=0;
    int n;
    //scanf("%d",&n);
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        int input;
        //scanf("%d",&input);
        cin>>input;
        a+=input;
    }
    for(int i = 1;i<=n;i++)
    {
        int input;
        //scanf("%d",&input);
        cin>>input;
        b+=input;
    }
    double ans=(a*3-b*2)*1.0/(a-b)*1.0;
    printf("%.6f",ans);
    return 0;

}