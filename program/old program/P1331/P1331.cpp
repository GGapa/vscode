#include <iostream>
#include <cstdio>
using namespace std;
char map[1002][1002];
bool used[1002][1002];
int number[1002][1002];
int ans=0;
int main()
{
    int R,C;
    cin>>R>>C;
    for(int i = 1;i<=R;i++)
    {
        for(int j = 1;j<=C;j++)
        {
            cin>>map[i][j];
            if(map[i][j]=='#')number[i][j]=number[i-1][j]+number[i][j-1]-number[i-1][j-1]+1;
            else number[i][j]=number[i-1][j]+number[i][j-1]-number[i-1][j-1];
            cout<<number[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i = 1;i<=R;i++)
    {
        for(int j = 1;j<=C;j++)
        {
            int l=i,w=j;//长 宽
            if(map[i][j]=='#')
            {
                map[i][j]='.';
                while(map[l+1][j]=='#')map[l][j]='.',l++;
                //map[l+1][j]='.';
                while(map[i][w+1]=='#')map[i][w]='.',w++;
                //map[i][w+1]='.';
                cout<<(l+1-i)*(w+1-j)<<" "<<number[l][w]-number[l][j-1]-number[i-1][w]+number[i-1][j-1]<<endl;
                if((l+1-i)*(w+1-j)==number[l][w]-number[l][j-1]-number[i-1][w]+number[i-1][j-1])ans++;
                else {cout<<"Bad placement."<<endl;return 0;}
            }
        }
    }
    printf("There are %d ships.",ans/2);
    return 0;
}