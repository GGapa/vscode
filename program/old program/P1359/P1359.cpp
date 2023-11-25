#include <iostream>
#include <vector>
using namespace std;
int map[202][202];
int main()
{
    int n;
    cin>>n;
    for(int i = 1;i<=n-1;i++)
    {
        for(int j = i+1;j<=n+1-j;j++)
        {
            int input;
            cin>>input;
            map[i][j]=input;
            map[j][i]=input;
        }
    }
    int ans=0;
    
   
}