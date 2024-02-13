#include<bits/stdc++.h>
#include<graphics.h>  
using namespace std;

void posCode(char c[4],float x,float y, int xmin, int ymin, int xmax, int ymax)
{    
	c[0]=(x<xmin)?'1':'0';
	c[1]=(x>xmax)?'1':'0';
	c[2]=(y<ymin)?'1':'0';
	c[3]=(y>ymax)?'1':'0';
}
void cohenS_Clipping(char c[],char d[],float &x,float &y,float m,int xmin,int ymin,int xmax,int ymax)
{
	int flag=1,i=0;
	for (i=0;i<4;i++)
	{
		if(c[i]!='0' && d[i]!='0')
		{
			flag=0;
			break;
		}
		if(flag)
		{
			if(c[0]!='0')
			{
				y=m*(xmin-x)+y;
				x=xmin;
			}
			else if(c[1]!='0')
			{
				y=m*(xmax-x)+y;
				x=xmax;
			}
			else if(c[2]!='0')
			{
				x=((ymin-y)/m)+x;
				y=ymin;
			}
			else if(c[3]!='0')
			{
				x=((ymax-y)/m)+x;
				y=ymax;
			}
		}
		if (flag==0)
		cout<<"Line lying outside";
	}
}
int main()
{
	int gd=DETECT, gm, s;
    char path[13] = "C:\\dev\\BGI";
    initgraph(&gd, &gm, path);
    
	float x1,y1,x2,y2;
	float m;
	char c[4], d[4];
	int xmin=150, ymin=100, xmax=450, ymax=350;
	// cout<<"Enter the lower co-ordinates of window: ";
	// cin>>xmin>>ymin;
	// cout<<"Enter the upper co-ordinates of window: ";
	// cin>>xmax>>ymax;

	setcolor(WHITE);
	rectangle(xmin,ymin,xmax,ymax);
	cout<<"Enter x1: ";
	cin>>x1;
	cout<<"Enter y1: ";
	cin>>y1;
	cout<<"Enter x2: ";
	cin>>x2;
	cout<<"Enter y2: ";
	cin>>y2;

	cout<<"Before clipping"<<endl;
	setcolor(WHITE);
	rectangle(xmin,ymin,xmax,ymax);
	line(x1,y1,x2,y2);
	delay(2000);
	cleardevice();

	m=float((y2-y1)/(x2-x1));
	posCode(c,x1,y1,xmin,ymin,xmax,ymax);
	posCode(d,x2,y2,xmin,ymin,xmax,ymax) ;
	cohenS_Clipping(c,d,x1,y1,m,xmin,ymin,xmax,ymax);
	cohenS_Clipping(d,c,x2,y2,m,xmin,ymin,xmax,ymax);
	cout<<"After Clipping";
	setcolor(WHITE);
	rectangle(xmin,ymin,xmax,ymax);
	line(x1,y1,x2,y2);

	getch();
	closegraph();
	return 0;
}

// TBRL