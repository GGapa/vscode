// P1032 [NOIP2002 提高组] 字串变换
#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <limits.h>
using namespace std;
const int maxn = 6 + 3;
string S[maxn], T[maxn];
map<string, int> H;
int main()
{
    string A, B;
    cin >> A >> B;
    int n = 1;
    for (n = 1; cin >> S[n] >> T[n]; n++)
        ;
    n--;
    queue<string> Q;
    if(A==B)
    {
        puts(0);
        return 0;
    }
    Q.push(A);
    H[A]=0;
    while (!Q.empty())
    {
        string u = Q.front();
        Q.pop();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < u.size(); j++)
            {
                if (u.substr(j, S[i].length()) == S[i])
                {
                    string v;
                    v=u.substr(0,j)+T[i]+u.substr(j+S[i].length(),INT_MAX);
                    if(!H.count(v))       
                    {
                        H[v]=H[u]+1;
                        if(v==B)
                        {
                            cout<<H[v]<<endl;
                            return 0;
                        }
                        if(H[v]<10)
                        {
                            Q.push(v);
                        }
                    }
                }
            }
        }
    }
    cout<<"NO ANSWER!\n";
    return 0;
}