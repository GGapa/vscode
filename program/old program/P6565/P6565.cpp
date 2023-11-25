#include <iostream>
#include <string>
using namespace std;
string a;
string b;
int main()
{
    int c;
    cin >> c;
    int d = 0;
    int e = 0;//max
    string f[111],message[111],name[111];
    int sos[111];
    int g = 0;
    for (int i = 1; i <= c; i++)
    {
        cin>>name[i]>>message[i];
        d = 0;
        for (int j = 0; j < message[i].size() - 2 ; j++)
        {
            if(j>=message[i].length())break;
            if (message[i][j] == 115 && message[i][j + 1] == 111 && message[i][j + 2] == 115)
                d++;
        }
        sos[i]=d;
        if(d>e)e=d;
    }
    for (int i = 1; i <= c; i++)
    {
        if(sos[i]==e)
        {
            cout<<name[i]<<" ";
        }
    }
    cout << endl;
    cout << e << endl;
}