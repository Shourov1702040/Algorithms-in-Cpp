#include<bits/stdc++.h>
#include<graphics.h>  
using namespace std;

int main()
{
    int gd=DETECT, gm, s;
    char path[13] = "C:\\dev\\BGI";
    initgraph(&gd, &gm, path);

    int x1=200,y1=300,x2=500,y2=300,x3=350,y3=400;
    cout<<"triangle before reflection"<<endl;
    setcolor(3);
    line(x1,y1,x2,y2);
    line(x1,y1,x3,y3);
    line(x2,y2,x3,y3);
    cout<<"triangle after reflection"<<endl;
    setcolor(5);
    line(x1,-y1+500,x2,-y2+500);
    line(x1,-y1+500,x3,-y3+500);
    line(x2,-y2+500,x3,-y3+500);
    getch();

    closegraph();
    return 0;
}