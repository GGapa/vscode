// P3378 【模板】堆
#include <iostream>
#include <queue>
#include <functional>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long> > q;
int main()
{
    long long op, n;
    cin >> n;
    while (n--)
    {
        cin >> op;
        if (op == 1)
        {
            long long x;
            cin >> x;
            q.push(x);
        }
        if (op == 2)
        {
            cout << q.top() << endl;
        }
        if (op == 3)
        {
            q.pop();
        }
    }
    return 0;
}