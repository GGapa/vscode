// P1168 中位数
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n;
vector<int> a;
int main()
{
    cin >> n;
    for (int i = 1, x; i <= n; i++)
    {
        scanf("%d", &x);
        a.insert(lower_bound(a.begin(), a.end(), x), x);
        if (i % 2 == 1)
        {
            printf("%d\n", a[(i - 1) / 2]);
        }
    }
    return 0;
}