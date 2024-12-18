// T297733 202212D 数字口袋
#include <iostream>
using namespace std;

int main()
{
    int maxx, total = 0, i = 1;
    cin >> maxx;
    do
    {
        total += i;
        if (total <= maxx)
            cout << i << endl;
        i++;
    } while (total <= maxx);
    return 0;
}