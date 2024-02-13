#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void drawCircle(int x, int y, int xc, int yc)
{
	putpixel(x+xc, y+yc,7);
	putpixel(-x+xc, y+yc,7);
	putpixel(x+xc, -y+yc,7);
	putpixel(-x+xc, -y+yc, 7);
	putpixel(y+xc, x+yc, 7);
	putpixel(y+xc, -x+yc, 7);
	putpixel(-y+xc, x+yc, 7);
	putpixel(-y+xc, -x+yc, 7);
}

int main()
{
	int gd = DETECT, gm;
	char path[13] = "C:\\dev\\BGI";
	int r, xc, yc, pk, x, y;
	initgraph(&gd, &gm, path);
	cout<<"Enter the center co-ordinates: ";
	cin>>xc>>yc;
	cout<<"Enter the radius of circle: ";
	cin>>r;
	pk = 1 - r;
	x = 0;
	y = r;
	while(x < y)
	{
		drawCircle(x,y,xc,yc);
		++x;
		if(pk < 0)
		{
			pk = pk + (2*x) + 1;
		}
		else
		{
			--y;
			pk = pk + (2*x) + 1 - (2*y);
		}
		delay(100);
	}
	getch();
	// closegraph();

	return 0;
}

