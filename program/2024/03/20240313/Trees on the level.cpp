#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val, ch[2];
    bool hasv;
    void init() { val = 0, hasv = false, ch[0] = ch[1] = 0; }
    bool set_val(int v)
    {
        if (hasv)
            return false;
        return val = v, hasv = true;
    }
};
Node A[256 + 4];
int sz;
int newNode() { return A[sz].init(), sz++; }
bool insert(int p, int val, const string &path)
{
    for (char c : path)
    {
        Node &x = A[p];
        int b = c == 'R';
        if (!x.ch[b])
            x.ch[b] = newNode();
        p = x.ch[b];
    }
    return A[p].set_val(val);
}
bool bfs(int p, vector<int> &ans)
{
    queue<int> Q;
    ans.clear(), Q.push(p);
    while (!Q.empty())
    {
        p = Q.front(), Q.pop();
        Node &x = A[p];
        if (!x.hasv)
            return false;
        ans.push_back(x.val);
        if (x.ch[0])
            Q.push(x.ch[0]);
        if (x.ch[1])
            Q.push(x.ch[1]);
    }
    return true;
}
void solve(const string &s)
{
    sz = 1;
    int root = newNode();
    stringstream ss(s);
    bool valid = true;
    for (string w; ss >> w;)
    {                           
        size_t i = w.find(','); 
        assert(i != string::npos);
        string val = w.substr(1, i - 1), path = w.substr(i + 1, w.size() - i - 2);
        if (!insert(root, stoi(val), path))
            valid = false;
    }
    vector<int> ans;
    if (valid && bfs(root, ans))
        for (int i = 0, n = ans.size(); i < n; i++)
            printf("%d%s", ans[i], (i == n - 1 ? "\n" : " "));
    else
        puts("not complete");
}
int main()
{
    for (string line, s; getline(cin, line);)
    {
        s += " " + line;
        int n = line.size();
        if (line.substr(n - 2) == "()")                  
            solve(s.substr(0, s.size() - 2)), s.clear(); 
    }
    return 0;
}
