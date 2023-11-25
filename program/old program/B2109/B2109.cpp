//B2109 统计数字字符个数
#include <iostream>
#include <cstring>
using namespace std;
string a;
int main()
{
    int ans=0;
    getline(cin,a);
    //a.getline();
    for(int i = 0;i<a.length();i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}