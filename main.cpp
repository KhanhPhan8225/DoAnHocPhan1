#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <dos.h>

using namespace std;

int getcolorcode(int code) {
    switch(code) {
        case 1: return RED;
        case 2: return GREEN;
        case 3: return BLUE;
        default: return WHITE;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x = 100, y = 100, dx = 5, dy = 5;
    int radius, colorchoice;

    cout << "Nhap ban kinh hinh tron: ";
    cin >> radius;

    cout << "Chon mau sac (1-Do, 2-Xanh la, 3-Xanh duong): ";
    cin >> colorchoice;

    int color = getcolorcode(colorchoice);
    int screenWidth = getmaxx ();
    int screenHeight = getmaxy ();

    while (true) {
        cleardevice();

        setcolor(color);
        setfillstyle(SOLID_FILL, color);
        circle(x, y, radius);
        floodfill(x, y, color);

        delay(5); 

        x += dx;
        y += dy;
        if (x - radius <= 0 || x + radius >= screenWidth) dx = -dx;
        if (y - radius <= 0 || y + radius >= screenHeight) dy = -dy;

    }

    closegraph();
    return 0;
}

