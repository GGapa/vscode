// P1106 删数问题
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string n;
int k;

int main()
{
    cin >> n >> k;
    while (k--)
    {
        string minstring = n;
        for (int i = 0; i < n.length(); i++)
        {
            string tmp;
            tmp += n.substr(0, i);
            tmp += n.substr(i + 1, n.length() - i - 1);
            minstring = min(minstring, tmp);
        }
        n = minstring;
    }
    string finalstr;
    bool firstnum=false;
    for (int i = 0; i < n.length(); i++)
    {
        if (n[i] != '0')
        {
            firstnum=true;
        }
        if(firstnum==true)
        {
            finalstr+=n[i];
        }
    }
    if (finalstr.length()==0)
        cout << 0 << endl;
    else
    {
        cout << finalstr << endl;
    }
    return 0;
}