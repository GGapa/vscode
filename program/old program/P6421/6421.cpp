#include <iostream>
//#include <cstdio>
using namespace std;
//const int maxn = 1005;
int n, k, num = 0;
// bool a[maxn];
bool a[1005];
int main()
{
    // scanf("%d %d", &n, &k);
    cin >> n >> k;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == true)
            continue;
        for (int j = i; j <= n; j += i)
        {
            if (a[j] == false)
            {
                num++;
                a[j] = true;
            }
            if (num == k)
            {
                // printf("%d",j);
                cout << j << endl;
                return 0;
            }
        }
    }
    return 0;
}