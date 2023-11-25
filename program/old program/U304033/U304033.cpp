// U304033 [_-0 C] 猜数
#include <vector>
#include <iostream>
using namespace std;
#define ll long long
ll n, p, q;
struct Gue
{
    ll left, right, order, middle;
    bool tag = false;
};
vector<Gue> a;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p >> q;
    char c = ' ';
    ll l = 1, r = n, from;
    ll cnt=0;
    while (c != '!' && c != '=')
    {
        cnt++;
        ll middle = (l + r) >> 1;
        a.push_back({l, r, c, middle});
        if (a[a.size() - 1].middle == a[a.size() - 2].middle)
        {
            double pp = (double)(p)/(double)(100);
            double mmax=pp*a.size()+3;
            a.erase(a.end()-mmax,a.end());
        }
        l=a[a.size()-1].left;
        r=a[a.size()-1].right; 
        cout << a[a.size() - 1].middle << endl;
        cin >> c;
        if (c == '<')
            l = middle;
        if (c == '>')
            r = middle;
    }
    return 0;
}