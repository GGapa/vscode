#include <bits/stdc++.h>
#define _for(i, a, b) for (int i = (a); i < (int)(b); ++i)
using namespace std;

const int MAXN = 1024;
vector<string> Words[MAXN];
size_t WL[MAXN];
int main()
{
    string line, word;
    int wc = 0, lc = 0; // 每一行单词数，行数
    fill_n(WL, MAXN, 0);
    while (getline(cin, line))
    {
        stringstream ss(line);
        int wi = 0;
        while (ss >> word)
            Words[lc].push_back(word), WL[wi] = max(WL[wi], word.size()), wi++;
        wc = max(wc, wi), lc++;
    }
    _for(i, 0, lc)
    {
        const vector<string> &ws = Words[i];
        _for(j, 0, ws.size())
        {
            int w = j < ws.size() - 1 ? WL[j] + 1 : 0;
            cout << left << setw(w) << ws[j];
        }
        cout << endl;
    }
    return 0;
}