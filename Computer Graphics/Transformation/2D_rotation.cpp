#include<bits/stdc++.h>
#include<graphics.h>  
using namespace std;

int main()
{
    int gd=DETECT, gm;
    char path[13] = "C:\\dev\\BGI";
    initgraph(&gd, &gm, path);

    long x1=200,y1=200,x2=100,y2=300,x3=200,y3=300;
    double a;

    line(x1,y1,x2,y2);
    line(x1,y1,x3,y3);
    line(x3,y3,x2,y2);


    cout<<"Rectangle without rotation"<<endl;
    cout<<"Angle of rotation:";
    cin>>a;

    a=(a*3.14)/180;
    x1=x1*cos(a) - y1*sin(a);
    x2=x2*cos(a) - y2*sin(a);
    x3=x3*cos(a) - y3*sin(a);

    y1=x1*sin(a)+y1*cos(a);
    y2=x2*sin(a)+y2*cos(a);
    y3=x3*sin(a)+y3*cos(a);

    setcolor(3);
    line(abs(x1)+40,abs(y1)+50,abs(x2)+40,abs(y2)+50);
    line(abs(x1)+40,abs(y1)+50,abs(x3)+40,abs(y3)+50);
    line(abs(x3)+40,abs(y3)+50,abs(x2)+40,abs(y2)+50);
    getch();

        
    closegraph();
    return 0;
}