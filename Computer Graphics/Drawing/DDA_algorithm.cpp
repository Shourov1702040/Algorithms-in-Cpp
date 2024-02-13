#include<bits/stdc++.h>
#include<graphics.h>  
using namespace std;

int main()  
{  
    int gd = DETECT ,gm;  
    float dx,dy,steps,m; 
    char path[13] = "C:/dev/BGI"; 
    int x0, x1, y0, y1, x, y;  
    initgraph(&gd, &gm, path);  

    cout<<"Enter co-ordinates of first point: ";  
    cin>>x0>>y0;  
    cout<<"Enter co-ordinates of second point: ";  
    cin>>x1>>y1;  

    dx = (float)(x1 - x0);  
    dy = (float)(y1 - y0); 
    m = dy/dx;

    if(dx>=dy)  
        steps = abs(dx);   
    else  
        steps = abs(dy); 

    x = x0;
    y = y0;
    putpixel(x,y,7);

    if (m<1)
    {
        for (int i = 0; i < steps; i++)
        {
            x = ceil(1+x);
            y = ceil(m)+y;
            putpixel(x,y,7);
            delay(60);
        }
    } 
    else if (m>1)
    {
        for (int i = 0; i < steps; i++)
        {
            x = ceil(1/m)+x;
            y = ceil(1+y);
            putpixel(x,y,7);
            delay(60);
        }
    }
    else
    {
        for (int i = 0; i < steps; i++)
        {
            x = ceil(1+x);
            y = ceil(1+y);
            putpixel(x,y,7);
            delay(60);
        }
    }

    getch();  
    closegraph(); 
    return 0; 
}