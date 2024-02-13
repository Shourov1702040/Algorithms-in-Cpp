#include<bits/stdc++.h>
#include<graphics.h>  
using namespace std;

int main()
{
    int gd=DETECT, gm, s;
    char path[13] = "C:\\dev\\BGI";
    initgraph(&gd, &gm, path);

    int x1=200,y1=100,x2=400,y2=100,x3=200,y3=200,x4=400,y4=200,Tx = 90, Ty=130;
    cout<<"Before Translation of rectangle (White)"<<endl;
    setcolor(7);
    line(x1,y1,x2,y2);
    line(x1,y1,x3,y3);
    line(x3,y3,x4,y4);
    line(x2,y2,x4,y4);

    cout<<"After Translation of rectangle (Blue)"<<endl;
    x1=x1+Tx;
    x2=x2+Tx;
    x3=x3+Tx;
    x4=x4+Tx;

    y1=y1+Ty;
    y2=y2+Ty;
    y3=y3+Ty;
    y4=y4+Ty;

    setcolor(3);
    line(x1,y1,x2,y2);
    line(x1,y1,x3,y3);
    line(x3,y3,x4,y4);
    line(x2,y2,x4,y4);
    getch();
        
    closegraph();
    return 0;
}