#include <string>
#include <iostream>
#include <cstdio>
#include <windows.h>
using namespace std;

int main()
{
    bool bj;
    string a;
    cout << "���룺\n";
    getline(cin, a);
    // a=" "+a;
    cout << "����(0)���ǽ���(1)\n";
    cin >> bj;
    cout << "������Կ" << endl;
    int passkey;
    cin >> passkey;
    if (bj)
    {
        // passkey++;
        passkey = a.length() / passkey;
        for (int i = 0; i < passkey; i++)
        {
            int tmp = 0;
            cout << a[i];
            bool out=false;
            for (int j = i; j < a.length(); j++)
            {
                tmp++;
                if(out)
                {
                    out=false;
                    cout<<a[j];
                }
                if (tmp == passkey)
                {
                    tmp = 0;
                    out=true;
                }
            }
        }
        cout << endl;
        cout << "����Ϊ" << a.length() << "   ������ԿΪ:" << passkey << endl;
    }
    else
    {
        int lll = a.length() % passkey;
        for (int i = 1; i <= passkey - lll; i++)
        {
            a += '.';
        }
        int keyout = 0;
        for (int i = 0; i < passkey; i++)
        {
            int tmp = 0;
            keyout++;
            cout << a[i];
            bool out=false;
            for (int j = i; j < a.length(); j++)
            {
                tmp++;
                if(out)
                {
                    out=false;
                    cout<<a[j];
                }
                if (tmp == passkey)
                {
                    tmp = 0;
                    out=true;
                }
            }
        }
        cout << endl;
        cout << "����Ϊ" << a.length() << "   ������ԿΪ:" << passkey << endl;
    }
    system("pause");
    return 0;
}

