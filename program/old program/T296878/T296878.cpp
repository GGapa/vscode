// T296878 「UOI-R1」磁铁
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

namespace spacea
{
    void Main(string a, string b)
    {
        if (b.length() == 1 && a == b)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
}
namespace spaceb
{
    void Main(string a, string b)
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == b[0])
            {
                cout << "Y" << endl;
                return;
            }
        }
        cout << "N" << endl;
    }
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        if (a.length() == 1)
        {
            spacea::Main(a, b);
            continue;
        }
        if (b.length() == 1)
        {
            spaceb::Main(a, b);
            continue;
        }
    }
}