// T298770 202212H1 狠狠地切割(Easy Version)
#include <iostream>
using namespace std;
int a[5000005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int total = 1;
    for (int i = 1; i <= m; i++)
    {
        int input;
        cin >> input;
        for (int j = 1; j <= n; j++)
        {
            if (a[j] == input)
            {
                a[j] = 0;
                if (a[j - 1] != 0 && a[j + 1] != 0 && (j - 1 > 0 && j + 1 <= n))
                    total++;
            }
        }
    }
    cout << total << endl;
    return 0;
}