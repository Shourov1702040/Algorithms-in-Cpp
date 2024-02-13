#include<bits/stdc++.h>
#include<graphics.h>  
using namespace std;

int main()
{
    int gd=DETECT, gm, s;
    char path[13] = "C:\\dev\\BGI";
    initgraph(&gd, &gm, path);

    int x1=50,y1=100,x2=150,y2=100,x3=50,y3=200,x4=150,y4=200,shx=2;
    cout<<"Before shearing of rectangle"<<endl;
    setcolor(3);
    line(x1,y1,x2,y2);
    line(x1,y1,x3,y3);
    line(x3,y3,x4,y4);
    line(x2,y2,x4,y4);
    cout<<"After shearing of rectangle"<<endl;

    x1=x1+shx*y1;
    x2=x2+shx*y2;
    x3=x3+shx*y3;
    x4=x4+shx*y4;

    setcolor(13);
    line(x1,y1,x2,y2);
    line(x1,y1,x3,y3);
    line(x3,y3,x4,y4);
    line(x2,y2,x4,y4);
    getch();

    closegraph();
    return 0;
}