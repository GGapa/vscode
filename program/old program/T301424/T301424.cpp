// T301424 『MdOI R5』Jump 偏分
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int aa[50000];
void init()
{
    for (int i = 0; i <= 31622; i++)
    {
        aa[i] = pow(2, i);
    }
}

int main()
{
    aa[0] = 1;
    int n;
    long long x = 0, num = 1;
    init();
    scanf("%d", &n);
    while (n--)
    {
        x = 0;
        num = 1;
        int k;
        bool succeed = false;
        scanf("%d", &k);
        double bl=sqrt(k);
        if(k==1)
        {
            cout<<1<<endl;
            continue;
        }
        for (int i = 0; i <= 31622; i++)
        {
            if(aa[i]==k&&aa[i]!=1)
            {
                cout<<-1<<endl;
                break;
            }
            else if(aa[i]>k)
            {
                cout<<i<<endl;
                break;
            }

            /*
            
            if (aa[i] == k)
            {
                succeed = true;
                printf("%d\n", i);
                break;
            }
            if (aa[i] > k)
            {
                long long temp = aa[i];
                for (int j = i - 1; j >= 1; j--)
                {
                    if (temp == k)
                    {
                        succeed = true;
                        printf("%d\n", i);
                        break;
                    }
                    if (temp > k)
                        temp -= aa[j];
                    else if (temp < k)
                        temp += aa[j];
                }
                break;
            }
            */
        }
        /*
        if (succeed == false)
        {
            printf("-1\n");
        }
        */
    }
    return 0;
}