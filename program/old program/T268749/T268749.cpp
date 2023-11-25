// T268749 「UOI-R1」智能推荐
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct stru
{
    int num=0, s, day = 0;
    bool used = false;
    vector<int> need;
} sub[5005];
map<int, bool> pass;
bool cmp(stru x, stru y)
{
    return x.s < y.s;
}
vector<int> needadd;
int main()
{
    int n, k, p, r, totaluse = 0;
    scanf("%d%d%d", &n, &k, &p);
    totaluse += p;
    for (int i = 1; i <= p; i++)
    {
        int input;
        scanf("%d", &input);
        sub[input].used = true;
        sub[input].s = 0;
        sub[input].num = input;
        pass[input] = true;
    }
    scanf("%d", &r);
    for (int i = 1; i <= r; i++)
    {
        int v, s;
        scanf("%d%d", &v, &s);
        sub[v].num = v;
        sub[v].s = s;
        for (int i = 0; i < s; i++)
        {
            int input;
            scanf("%d", &input);
            sub[v].need.push_back(input);
        }
    }
    sort(sub + 1, sub + 1 + k, cmp);
    bool next = true;
    int it = 0, date = 0;
    while (next)
    {
        needadd.clear();
        if (pass[k])
        {
            printf("%d\n", date);
            return 0;
        }
        next = false;
        for (int i = 1; i <= n; i++)
        {
            bool succeed = true;
            if (pass[sub[i].num]||sub[i].num==0)
                continue;
            if(sub[i].s>totaluse)continue;
            for (int j = 0; j < sub[i].need.size(); j++)
            {
                if (!pass[sub[i].need[j]])
                {
                    succeed = false;
                    break;
                }
            }
            if (succeed)
            {
                needadd.push_back(i);
                next = true;
            }
        }
        date++;
        for (int i = 0; i < needadd.size(); i++)
        {
            pass[sub[needadd[i]].num] = true;
            totaluse++;
        }
    }
    printf("-1\n");
    return 0;
}