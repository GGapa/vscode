#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int D[] = {2, 3, 2, 3, 2};
string M[3][3];
vector<vector<int>> S[3][3];
int P[9][9];
bool X[9][10];
bool Y[9][10];
void dfs(int i, int j)
{
    if (i == 3)
    {
        for (i = 0; i <= 8; i++)
        {
            for (j = 0; j <= 8; j++)
            {
                cout << P[i][j] << " \n"[j == 8];
            }
        }
        exit(0);
    }
    for (auto &A : S[i][j])
    {
        int N[3][3], t = 0;
        for (int a = 0; a <= 2; a++)
        {
            for (int b = 0; b <= 2; b++)
            {
                N[a][b] = A[t++];
            }
        }
        bool f = true;
        for (int a = 0; a <= 2; a++)
        {
            for (int b = 0; b <= 2; b++)
            {
                int u = 3 * i + a;
                int v = 3 * j + b;
                f &= X[u][N[a][b]] == false;
                f &= Y[v][N[a][b]] == false;
            }
        }
        if (f == true)
        {
            for (int a = 0; a <= 2; a++)
            {
                for (int b = 0; b <= 2; b++)
                {
                    int u = 3 * i + a;
                    int v = 3 * j + b;
                    P[u][v] = N[a][b];
                    X[u][N[a][b]] = true;
                    Y[v][N[a][b]] = true;
                }
            }
            if (j == 2)
            {
                dfs(i + 1, 0);
            }
            else
                dfs(i, j + 1);
            for (int a = 0; a <= 2; a++)
            {
                for (int b = 0; b <= 2; b++)
                {
                    int u = 3 * i + a;
                    int v = 3 * j + b;
                    X[u][N[a][b]] = false;
                    Y[v][N[a][b]] = false;
                }
            }
        }
    }
}
int main()
{
    for(int i = 0;i<=2;i++)
    {
        for(int d=0;d<=4;d++)
        {
            for(int j = 0;j<=2;j++)
            {
                for(int k = 0;k<=D[d] - 1;k++)
                {
                    char c; cin >> c;
                    M[i][j].push_back(c);
                }
            }
        }
    }
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            do
            {
                int N[3][3], t = 0;
                for (int a = 0; a <= 2; a++)
                {
                    for (int b = 0; b <= 2; b++)
                    {
                        N[a][b] = A[t++];
                    }
                }
                bool f = true;
                f &= ((N[0][0] > N[0][1]) == (M[i][j][0] == '>'));
                f &= ((N[0][1] > N[0][2]) == (M[i][j][1] == '>'));
                f &= ((N[1][0] > N[1][1]) == (M[i][j][5] == '>'));
                f &= ((N[1][1] > N[1][2]) == (M[i][j][6] == '>'));
                f &= ((N[2][0] > N[2][1]) == (M[i][j][10] == '>'));
                f &= ((N[2][1] > N[2][2]) == (M[i][j][11] == '>'));

                f &= ((N[0][0] > N[1][0]) == (M[i][j][2] == 'v'));
                f &= ((N[0][1] > N[1][1]) == (M[i][j][3] == 'v'));
                f &= ((N[0][2] > N[1][2]) == (M[i][j][4] == 'v'));
                f &= ((N[1][0] > N[2][0]) == (M[i][j][7] == 'v'));
                f &= ((N[1][1] > N[2][1]) == (M[i][j][8] == 'v'));
                f &= ((N[1][2] > N[2][2]) == (M[i][j][9] == 'v'));
                if (f == true)
                {
                    S[i][j].push_back(A);
                }
            } while (next_permutation(A.begin(), A.end()));
        }
    }
    dfs(0, 0);
    return 0;
}