//T290172 202212A 不可以，总司令
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int x,y;
    cin>>x>>y;
    if(x>y)cout<<"no"<<endl;
    else if(x<y)cout<<"yes"<<endl;
    else cout<<"equal probability"<<endl;
    return 0;
}