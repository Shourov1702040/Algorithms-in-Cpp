#include<bits/stdc++.h>
#include<graphics.h>  
using namespace std;

int main()  
{  
    char path[13] = "C:\\dev\\BGI";
    int gdriver=DETECT, gmode, x0, y0, x1, y1, dx, dy, Pk, x, y;  
    initgraph(&gdriver, &gmode, path);  

    cout<<"Enter co-ordinates of first point: ";  
    cin>>x0>>y0;  
    cout<<"Enter co-ordinates of second point: ";  
    cin>>x1>>y1;  

    dx = x1-x0;  
    dy = y1-y0;  
    x = x0;  
    y = y0;  
    putpixel(x,y,7);
    Pk = 2*dy-dx;  

    while(x<x1)  
    {  
        if(Pk>=0)  
        {  
            Pk = Pk+2*dy-2*dx; 
            x = x+1; 
            y = y+1;
            putpixel(x,y,7); 
        }  
        else  
        {     
            Pk = Pk+2*dy;
            x = x+1;
            putpixel(x,y,7); 
        }  
        delay(100);    
    } 

    getch();
    closegraph();
    return 0;  
}  