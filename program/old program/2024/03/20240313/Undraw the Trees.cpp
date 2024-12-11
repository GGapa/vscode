// Undraw the Trees
#include <bits/stdc++.h>
using namespace std;
vector<string> G;

void dfs(int r, int c)
{
    if (isspace(G[r][c]) || G[r][c] == '#')
        return;
    printf("%c(", G[r][c]);
    int n = G.size(), r1 = r + 1, r2 = r + 2, r3 = r + 3;
    if (r1 < n && G[r1][c] == '|')
    {
        size_t l = c;
        while (l - 1 >= 0 && G[r2][l - 1] == '-')
            l--;
        for (; l < G[r3].size() && G[r2][l] == '-'; l++)
            dfs(r3, l);
    }
    printf(")");
}
void solve()
{
    G.clear();
    for (string s; getline(cin, s) && s != "#"; G.push_back(s)) ;
    printf("(");
    if (!G.empty())
        for (size_t i = 0; i < G[0].size(); i++)
            if (G[0][i] != ' ')
            {
                dfs(0, i);
                break;
            }
    puts(")");
}
int main()
{
    int T;
    cin >> T, cin.ignore();
    while (T--)
        solve();
    return 0;
}