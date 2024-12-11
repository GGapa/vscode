// P3435 [POI2006] OKR-Periods of Words

#include <iostream>
using namespace std;
const int maxn = 1000000 + 5;
int Next[maxn];
string a;
int n;
unsigned long long cnt;
void GetNext()
{
    for (int i = 1, j = 0; i < n; i++)
    {
        while (j && a[i] != a[j])
            j = Next[j];
        j += (a[i] == a[j]);
        Next[i + 1] = j;
    }
}
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> a;
    GetNext();
    for (int i = 1, j; i <= n; i++)
    {
        j = i;
        while (Next[j])
            j = Next[j];
        if (Next[i] != 0)
            Next[i] = j;
        cnt += i - j;
    }
    cout << cnt << endl;
    return 0;
}
