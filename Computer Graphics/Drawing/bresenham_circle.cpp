#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int main()
{
    double x1, y1, r, x, y, Pk;
    char path[13] = "C:\\dev\\BGI";
    int gd = DETECT, gm;
    initgraph(&gd, &gm, path);

    cout<<"Enter the starting co - ordinates of a center (x, y): ";
    cin>> x1 >> y1;
    cout<<"Enter the value of radius: ";
    cin>> r;

    x = 0;
    y = r;
    Pk = 3 - (2 * r);
    while(x <= y)
    {
        putpixel(x1 + x, y1 + y, WHITE);
        putpixel(x1 - x, y1 + y, WHITE);
        putpixel(x1 + x, y1 - y, WHITE);
        putpixel(x1 - x, y1 - y, WHITE);
        putpixel(x1 + y, y1 + x, WHITE);
        putpixel(x1 + y, y1 - x, WHITE);
        putpixel(x1 - y, y1 + x, WHITE);
        putpixel(x1 - y, y1 - x, WHITE);

        x = x + 1;
        if(Pk<0)
            Pk = Pk + 4*(x) + 6;
        else
        {
            Pk = Pk + 4*(x - y) + 10;
            y = y - 1;
        }

        delay(100);
    }
    getch();
    closegraph();

    return 0;
}