#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
char yuan[5]={'a','e','i','o','u'};
string a;
int main()
{
    getline(cin,a);
    for(int i = 0;i<a.length();i++)
    {
        for(int j = 0;j<5;j++)
        {
            if(a[i]==yuan[j])
            {
                a.erase(i+1,2);
            }
        }
    }
    cout<<a<<endl;
    return 0;
    return 0;
}