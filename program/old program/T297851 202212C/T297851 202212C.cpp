//T297851 202212C 洛谷三角洲
#include <iostream>
using namespace std;

int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    cout<<min(x,y+z)<<"\n"<<min(y,x+z)<<"\n"<<min(z,x+y)<<endl;
    return 0;
}