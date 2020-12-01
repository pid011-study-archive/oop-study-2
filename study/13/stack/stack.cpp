#include <iostream>
using namespace std;

template<class T>
class CStack {
    const size_t Max{10};
    T _stack[10]{};
    size_t _top{0};

public:
    void push(T item) {
        if (_top >= Max) {
            cout << "스택이 꽉참" << endl;
            return;
        }
        _stack[_top++] = item;
    }

    bool pop(T& out) {
        if (_top == 0) {
            cout << "스택이 비어있음" << endl;
            return false;
        }

        out = _stack[--_top];
        return true;
    }

    size_t count() const {
        return _top;
    }
};

int main() {
    {
        CStack<int> stack;
        int num;
        for (int i = 0; i < 10; i++) {
            cout << "스택에 넣을 숫자를 입력하세요: ";
            cin >> num;
            stack.push(num);
        }
        cout << endl;
        cout << "갯수: " << stack.count() << endl;
        cout << "하나씩 꺼냅니다." << endl;
        for (int i = 0; i < 10; i++) {
            int outval{-1};
            stack.pop(outval);
            cout << 10 - i << "번 째로 넣은 숫자: " << outval << endl;
        }
    }
    cout << endl;
    {
        CStack<char> stack;
        char num;
        for (int i = 0; i < 10; i++) {
            cout << "스택에 넣을 문자를 입력하세요: ";
            cin >> num;
            stack.push(num);
        }
        cout << endl;
        cout << "갯수: " << stack.count() << endl;
        cout << "하나씩 꺼냅니다." << endl;
        for (int i = 0; i < 10; i++) {
            char outval{'\n'};
            stack.pop(outval);
            cout << 10 - i << "번 째로 넣은 문자: " << outval << endl;
        }
    }
}
