//P1355 神秘大三角
//参考资料:https://baike.baidu.com/item/%E4%BD%99%E5%BC%A6%E5%AE%9A%E7%90%86/957460
//图1：https://bkimg.cdn.bcebos.com/pic/8ad4b31c8701a18b715f3b239c2f07082838fe22?x-bce-process=image/resize,m_lfit,w_440,limit_1
//图2：https://sm.ms/image/HsEpDUSMz3omxtj
//图3：https://sm.ms/image/NWrmLzK6ZPwlIXy
//角度越大cos越小
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <random>
#include <time.h>
using namespace std;
int x[5],y[5];
char l;
double m(double x,double y,double z)
{
    double p=(x+y+z)/2;
    return sqrt(p*(p-x)*(p-y)*(p-z));
}
int main()
{
    cin>>l>>x[1]>>l>>y[1]>>l;
    cin>>l>>x[2]>>l>>y[2]>>l;
    cin>>l>>x[3]>>l>>y[3]>>l;
    cin>>l>>x[4]>>l>>y[4]>>l;
    double a=sqrt(pow((x[2]-x[3]),2)+pow((y[2]-y[3]),2)),
        b=sqrt(pow((x[1]-x[3]),2)+pow((y[1]-y[3]),2)),
        c=sqrt(pow((x[2]-x[1]),2)+pow((y[2]-y[1]),2));
    double cos[4];
    cos[1]=(b*b+c*c-a*a)/(2*b*c);//cosa
    cos[2]=(c*c+a*a-b*b)/(2*a*c);//cosb
    cos[3]=(a*a+b*b-c*c)/(a*b*2);//cosc
    double da=sqrt(pow(x[4]-x[1],2)+pow(y[4]-y[1],2)),
        db=sqrt(pow(x[4]-x[2],2)+pow(y[4]-y[2],2)),
        dc=sqrt(pow(x[4]-x[3],2)+pow(y[4]-y[3],2));
    double cosd[4];
    cosd[1]=(da*da+c*c-db*db)/(2*da*c);//cosdab
    cosd[2]=(db*db+c*c-da*da)/(2*db*c);//cosdba
    cosd[3]=(da*da+db*db-c*c)/(2*da*db);//cosadb
    for(int i = 1;i<=3;i++)//如果在顶点上
    {
        if(x[4]==x[i]&&y[4]==y[i])
        {
            printf("4");
            return 0;
        }
    }
    bool outside,//是否超出边界
        online;//在边所在直线上
    for(int i = 1;i<=3;i++)
    {
        if((cos[i])*100==(cosd[i])*100)online=true;
        if(cos[i]>cosd[i]&&i!=3)outside=true;
        if(cos[i]<cosd[i]&&i==3)outside=true;
    }
    cosd[1]=(b*b+da*da-dc*dc)/(2*b*da);//cosdac
    cosd[2]=(da*da+dc*dc-b*b)/(2*da*dc);//cosadc
    cosd[3]=(b*b+dc*dc-da*da)/(2*b*dc);//cosacd
    for(int i = 1;i<=3;i++)
    {
        if((cos[i]*100)==(cosd[i])*100)online=true;
        if(cos[i]>cosd[i]&&i!=2)outside=true;
        if(cos[i]<cosd[i]&&i==2)outside=true;
    }
    double abc=(int)m(a,b,c)*100,abd=(int)m(da,db,c)*100,acd=(int)m(da,dc,b)*100,bcd=(int)m(a,db,dc)*100;
    
    if(abd+acd+bcd>abc)
    {
        printf("2");
    }
    else if(!abc||!abd||!acd||!bcd)
    {
        printf("3");
    } 
    else
    {
        printf("1");
    }
    return 0;
}