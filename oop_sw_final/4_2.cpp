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

// ColoredCircle 함수는 Circle을 상속받고
// color 멤버변수를 가진다.
class ColoredCircle : public Circle {
private:
    string color;

public:
    
    // 생성자를 통해 멤버 변수를 모두 초기화.
    ColoredCircle(int _x, int _y, int _radius, string _color) : Circle(_x, _y, _radius), color(_color) {}

    void draw()
    {
        // 화면 상에 그림을 그리기 위해 HDC 객체 생성.
        // 화면에 그릴 한 원에는 생성자를 통해 전달받은
        // 색깔을 지정해주어야 한다.
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

        // 지정한 색깔과 크기를 갖는 원(타원)을 그린다.
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