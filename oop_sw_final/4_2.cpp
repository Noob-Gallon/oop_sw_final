#include <iostream>
#include <windows.h>

using namespace std;

class Circle {
    int x, y, radius;

public:

    Circle(int _x, int _y, int _r) : x(_x), y(_y), radius(_r) {}

    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    int getRadius() {
        return radius;
    }
};

class ColoredCircle : public Circle {
private:
    string color;

public:

    ColoredCircle(int _x, int _y, int _radius, string _color) : Circle(_x, _y, _radius), color(_color) {}

    void draw()
    {
        HDC hdc = GetWindowDC(GetForegroundWindow());
        SelectObject(hdc, GetStockObject(DC_BRUSH));

        if (color == "red") {
            SetDCBrushColor(hdc, RGB(255, 0, 0));

        }
        else if (color == "green") {
            SetDCBrushColor(hdc, RGB(0, 255, 0));

        }
        else if (color == "blue") {
            SetDCBrushColor(hdc, RGB(0, 0, 255));

        }
        else {
            SetDCBrushColor(hdc, RGB(255, 255, 255));

        }

        Ellipse(hdc, getX() - getRadius(), getY() - getRadius(), getX() + getRadius(), getY() + getRadius());
    }
};

int main() {

    ColoredCircle c1(100, 250, 10, "white");
    ColoredCircle c2(200, 250, 10, "red");

    c1.draw();
    c2.draw();

    return 0;
}