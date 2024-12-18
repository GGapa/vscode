// UVA11995 I Can Guess the Data Structure!
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
queue<int> que;
priority_queue<int> proque;
stack<int> sta;
int ans = 0;
bool ifque = true, ifproque = true, ifsta = true;
int x, y;
int main()
{
    int n;
    while (scanf("%d", &n)==1)
    {
        ifque = true, ifproque = true, ifsta = true;
        ans = 3;
        while (!que.empty())
            que.pop();
        while (!proque.empty())
            proque.pop();
        while (!sta.empty())
            sta.pop();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d", &x, &y);
            if (x == 1)
            {
                que.push(y);
                sta.push(y);
                proque.push(y);
            }
            else
            {
                if (que.empty())
                    ifque = false;
                else if (y != que.front())
                    ifque = false;
                if (sta.empty())
                    ifsta = false;
                else if (y != sta.top())
                    ifsta = false;
                if (proque.empty())
                    ifproque = false;
                else if (y != proque.top())
                    ifproque = false;
                if (!proque.empty())proque.pop();
                if (!sta.empty())sta.pop();
                if (!que.empty())que.pop();
            }
        }
        if (((ifsta && !(ifproque||ifque)||(ifproque&&!(ifsta||ifque))||(ifque&&!(ifproque||ifsta)))))
        {
            if (ifsta)
            {
                cout << "stack" << endl;
            }
            else if (ifproque)
            {
                cout << "priority queue" << endl;
            }
            else if (ifque)
            {
                cout << "queue" << endl;
            }
        }
        else if (!(ifsta || ifque || ifproque))
        {
            cout << "impossible" << endl;
        }
        else
        {
            cout << "not sure" << endl;
        }
    }
    return 0;
}