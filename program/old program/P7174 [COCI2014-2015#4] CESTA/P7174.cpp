// P7174 [COCI2014-2015#4] CESTA
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
string a;
bool cmp(char x, char y)
{
    return x > y;
}
int main()
{
    cin >> a;
    bool zero = false;
    int sum = 0;
    for (int i = 0; i < a.length(); i++)
    {
        sum = sum + a[i] - '0';
        if (a[i] == '0')
            zero = true;
    }
    if (sum % 3 == 0 && zero == true)
    {
        bool bj = true;
        sort(a.begin(),a.end(),cmp);
        /*
        TLE
        while (bj)
        {
            bj=false;
            for (int i = 0; i < a.length()-1; i++)
            {
                if(a[i]<a[i+1])swap(a[i],a[i+1]),bj=true;
            }
        }
        */
        cout << a << endl;
    }
    else
    {
        printf("-1");
    }
    return 0;
}