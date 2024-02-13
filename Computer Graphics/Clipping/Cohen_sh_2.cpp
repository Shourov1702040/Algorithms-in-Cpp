#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int xmin=150;
int ymin=100;
int xmax=450;
int ymax=350;
typedef struct coordinate
{
    int x,y;
    char code[4];
} PT;

void drawline(PT p1,PT p2);
PT setcode(PT p);
int visibility(PT p1,PT p2);
PT resetendpt(PT p1,PT p2);

int main()
{
    int gd=DETECT,v,gm;
    PT p1,p2,p3,p4,ptemp;

    cout<<"\nEnter x1 and y1\n";
    cin>>p1.x>>p1.y;
    cout<<"\nEnter x2 and y2\n";
    cin>>p2.x>>p2.y;

    char path[13] = "C:\\dev\\BGI";
    initgraph(&gd, &gm, path);

    rectangle(xmin,ymin,xmax,ymax);
    delay(500);

    drawline(p1,p2);
    delay(500);
    cleardevice();

    delay(500);
    p1=setcode(p1);
    p2=setcode(p2);
    v=visibility(p1,p2);
    delay(500);

    rectangle(xmin,ymin,xmax,ymax);
    delay(500);

    switch(v)
    {
    case 0:
        drawline(p1,p2);
        break;
    case 1:
        break;

    case 2:
        p3=resetendpt(p1,p2);
        p4=resetendpt(p2,p1);
        drawline(p3,p4);
        break;
    }

    delay(5000);
    closegraph();
}


void drawline(PT p1,PT p2)
{
    line(p1.x,p1.y,p2.x,p2.y);
}

PT setcode(PT p)	//for setting the 4 bit code
{
    PT ptemp;

    if(p.y< ymin)
        ptemp.code[0]='1';	//Top
    else
        ptemp.code[0]='0';

    if(p.y> ymax)
        ptemp.code[1]='1';	//Bottom
    else
        ptemp.code[1]='0';

    if(p.x> xmax)
        ptemp.code[2]='1';	//Right
    else
        ptemp.code[2]='0';

    if(p.x< xmin)
        ptemp.code[3]='1';	//Left
    else
        ptemp.code[3]='0';

    ptemp.x=p.x;
    ptemp.y=p.y;

    return(ptemp);
}

int visibility(PT p1,PT p2)
{
    int i,flag=0;

    for(i=0; i<4; i++)
    {
        if((p1.code[i]!='0') || (p2.code[i]!='0'))
            flag=1;
    }

    if(flag==0)
        return(0);

    for(i=0; i<4; i++)
    {
        if((p1.code[i]==p2.code[i]) && (p1.code[i]=='1'))
            flag='0';
    }

    if(flag==0)
        return(1);

    return(2);
}

PT resetendpt(PT p1,PT p2)
{
    PT temp;
    int x,y,i;
    double m,k;

    if(p1.code[3]=='1')
        x= xmin;

    if(p1.code[2]=='1')
        x= xmax;

    if((p1.code[3]=='1') || (p1.code[2]=='1'))
    {
        m=(double)(p2.y-p1.y)/(p2.x-p1.x);
        k=(p1.y+(m*(x-p1.x)));
        temp.y=k;
        temp.x=x;

        for(i=0; i<4; i++)
            temp.code[i]=p1.code[i];

        if(temp.y<=ymax && temp.y>= ymin)
            return (temp);
    }

    if(p1.code[0]=='1')
        y=ymin;

    if(p1.code[1]=='1')
        y=ymax;

    if((p1.code[0]=='1') || (p1.code[1]=='1'))
    {
        m=(double)(p2.y-p1.y)/(p2.x-p1.x);
        k=(double)p1.x+(double)(y-p1.y)/m;
        temp.x=k;
        temp.y=y;

        for(i=0; i<4; i++)
            temp.code[i]=p1.code[i];

        return(temp);
    }
    else
        return(p1);
}