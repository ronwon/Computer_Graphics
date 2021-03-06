#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;
#define PI 3.14159265

class point {
public:
    int x, y;
    point() {
        x = 0;
        y = 0;
    }
    point(int a, int b) {
        x = a;
        y = b;
    }
} p1, p2;

// ROTATE GIVEN POINT P BY I DEGREES ABOUT mx AND my POINTS
point rotByI(point p, int i, int mx, int my) {
    float c = cos(i*(PI/180));
    float s = sin(i*(PI/180));
    float x = p.x*c - p.y*s + mx + my*s - mx*c;
    float y = p.x*s + p.y*c + my - my*c - mx*s;
    return point(round(x), round(y));
}

// ROTATE GIVEN LINE
void rotateLine() {
    int midx = (p1.x+p2.x)/2;
    int midy = (p1.y+p2.y)/2;
    float i = 3;
    while(1) {
        p1 = rotByI(p1,i,midx,midy);
        p2 = rotByI(p2,i,midx,midy);
        cleardevice();
        line(p1.x,p1.y,p2.x,p2.y);
        delay(1);

    }

}

int main() {

    initwindow(600, 600);

    // LINE TO BE ROTATED
    p1.x = 150;p1.y = 300;
    p2.x = 450;p2.y = 300;

    rotateLine();

    getch();
    return 0;
}
