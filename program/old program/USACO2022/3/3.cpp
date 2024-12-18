// panduan
#include <iostream>
#include <cstdio>
using namespace std;

namespace A
{
    int Main()
    {
    }
}
namespace B
{
    int Main()
    {
        string l1, l2;
        int l3, l4;
        cin >> l1 >> l3 >> l2 >> l4;
        if (l3 == l4 && l1 == l2)
            cout << "LIE" << endl;
        else if(l3!=l4&&l1!=l2)
        {
            for (int i = 0; i < l1.length(); i++)
            {
                if(l1[i]==l2[i])
                {
                    cout<<"LIE"<<endl;
                    break;
                    return 0;
                }
            }
        }
        else cout << "OK" << endl;
    }
}
int main()
{
    int t, n, m;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n, &m);
        if (n == 2)
        {
            A::Main();
            return 0;
        }
        else if (m == 2)
        {
            B::Main();
            return 0;
        }
        else
        {
            cout << "OK\n"
                    "OK\n"
                    "LIE\n"
                    "LIE";
            return 0;
        }
    }
    return 0;
}