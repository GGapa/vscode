#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 1e6;
int main()
{
    for(int i = 2;i<=maxn;i++)
    {
        for(int j = i+1;j<=maxn;j++)
        {
            __gcd(i,j);
        }
    }
    return 0;
}