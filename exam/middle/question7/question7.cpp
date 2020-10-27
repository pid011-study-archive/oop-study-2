#include <iostream>

using namespace std;

class CShape {
private:
    int type;             // 1:정사각형, 2:원
    int len;              // 도형의 길이
    static int rectCount; // 정사각형의 개수
    static int circCount; // 원의 개수

public:
    CShape(int type, int len) {
        switch (type) {
        case 1:
            this->rectCount++;
            break;
        case 2:
            this->circCount++;
            break;
        default:
            break;
        }

        this->type = type;
        this->len = len;
    }

    double GetArea() {
        switch (type) {
        case 1:
            return (double)len * len;
        case 2:
            return (double)len * len * 3.14;
        default:
            return 0;
        }
    }

    static int GetRectCount() {
        return rectCount;
    }

    static int GetCircCount() {
        return circCount;
    }
};

int CShape::rectCount = 0;
int CShape::circCount = 0;

int main() {
    CShape s1(1, 5);
    cout << "s1의 면적:" << s1.GetArea() << endl;
    CShape s2(2, 5);
    cout << "s2의 면적:" << s2.GetArea() << endl;
    CShape* p = new CShape(1, 10);
    cout << "p의 면적:" << p->GetArea() << endl;

    cout << "사각형 개수: " << CShape::GetRectCount() << endl;
    cout << "원 개수: " << CShape::GetCircCount() << endl;
    return 0;
}
