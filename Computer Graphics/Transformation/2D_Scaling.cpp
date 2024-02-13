#include<bits/stdc++.h>
#include<graphics.h>  
using namespace std;

int main()
{
    int gd=DETECT, gm, s;
    char path[13] = "C:\\dev\\BGI";
    initgraph(&gd, &gm, path);

    int x1=100,y1=100,x2=200,y2=100,x3=200,y3=100,x4=200,y4=200, Sx = 2, Sy=2;
    cout<<"Before scaling"<<endl;
    setcolor(7);
    rectangle(x1,y1,x4,y4);

    cout<<"After scaling"<<endl;
    setcolor(3);
    rectangle(x1*Sx,y1*Sy,x4*Sx,y4*Sy);
    getch();

    closegraph();
    return 0;
}