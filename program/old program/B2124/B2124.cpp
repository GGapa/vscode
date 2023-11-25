//B2124 判断字符串是否为回文

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string in;
    cin>>in;
    int l=0,r=in.length()-1;
    while(l<=r)
    {
        if(in[l]!=in[r])
        {
            cout<<"no"<<endl;
            return 0;
        }
        l++;
        r--;
    }
    cout<<"yes"<<endl;
    return 0;
}