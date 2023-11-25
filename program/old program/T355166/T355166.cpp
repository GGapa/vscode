// T355166 链表 (chain)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
#define nl NULL
struct Node
{
    int value;
    Node *next;
};

void addedge(Node *&head, int value)
{
    Node *tmpnode = new Node;
    tmpnode->value = value;
    tmpnode->next = nl;
    if (head == nl)
        head = tmpnode;
    else
    {
        Node *tmp1 = head;
        while (tmp1->next != nl)
        {
            tmp1 = tmp1->next;
        }
        tmp1->next = tmpnode;
    }
}

int find(Node *head, int number)
{
    int tmp = 0;
    int sum = 0;
    Node *tmp1 = head;
    while (tmp1 != nl)
    {
        if (tmp1->value >= number)
        {
            sum++;
        }
        else if (sum > 0)
        {
            tmp++;
            sum = 0;
        }
        tmp1 = tmp1->next;
    }
    if (sum > 0)
    {
        tmp++;
    }
    return tmp;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    Node *head = nl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        addedge(head, a[i]);
    }
    int Last = 0;
    while (m--)
    {
        char op;
        cin >> op;
        if (op == 'Q')
        {
            int x;
            cin >> x;
            int number = x ^ Last;
            int ans = find(head, number);
            cout << ans << endl;
            Last = ans;
        }
        else if (op == 'C')
        {
            int k, y;
            cin >> k >> y;
            int flag = k ^ Last;
            Node *tmp1 = head;
            for (int i = 1; i < flag && tmp1 != nl; i++)
            {
                tmp1 = tmp1->next;
            }
            if (tmp1 != nl)
            {
                tmp1->value = y ^ Last;
            }
        }
    }
    return 0;
}  