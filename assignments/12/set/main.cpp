﻿#include <iostream>
using namespace std;

constexpr size_t MAX { 10 };

// 0은 없는 값으로 생각함
class Set {
    int elems[MAX] {};
    int num { 0 };

public:
    bool empty();
    bool member(int e);
    bool insert(int e);
    bool remove(int e);
    bool equal(Set* s);
    void set_union(Set* s1, Set* s2);
    void print();

    bool operator[](int e) {
        return member(e);
    }

    bool operator()(int e) {
        return insert(e);
    }

    bool operator-(int e) {
        return remove(e);
    }

    bool operator==(Set& compare) {
        return equal(&compare);
    }

    bool operator!=(Set& compare) {
        return !(*this == compare);
    }

    Set operator+(Set& s) {
        Set u;
        u.set_union(this, &s);
        return u;
    }
};

bool Set::empty() {
    return num == 0;
}

bool Set::member(int e) {
    if (e == 0) {
        return false;
    }

    for (int i = 0; i < num; i++) {
        if (elems[i] == e) {
            return true;
        }
    }
    return false;
}

bool Set::insert(int e) {
    if (e == 0 || num == MAX) {
        return false;
    }

    for (int i = 0; i < num; i++) {
        if (elems[i] == e) {
            return false;
        }
    }
    elems[num++] = e;
    return true;
}

bool Set::remove(int e) {
    if (e == 0 || num == 0) {
        return false;
    }

    for (int i = 0; i < num; i++) {
        if (elems[i] == e) {
            elems[i] = 0;
            num--;
            return true;
        }
    }
    return false;
}

bool Set::equal(Set* s) {
    for (int i = 0; i < num; i++) {
        if (!s->member(elems[i])) {
            return false;
        }
    }
    return true;
}

void Set::set_union(Set* s1, Set* s2) {

    for (int i = 0; i < s1->num; i++) {
        insert(s1->elems[i]);
    }
    for (int i = 0; i < s2->num; i++) {
        insert(s2->elems[i]);
    }
}

void Set::print() {
    cout << "(";
    for (int i = 0; i < num; i++) {
        cout << elems[i] << (i < num - 1 ? ", " : "");
    }
    cout << ")" << endl;
}

int main() {
    Set s1, s2, s3;

    s1(88);
    s1(33);
    s1(99);
    s1(77);

    s2(10);
    s2(20);
    s2(30);

    s1.print();
    s2.print();

    s1 - 77;
    cout << "s1 - (77) = ";
    s1.print();
    if (s2[20]) {
        cout << "20 is in s2\n";
    }

    if (s1 != s2) {
        cout << "s1 != s2\n";
    }

    s1.print();
    s3 = s1 + s2;
    cout << "s3 = s1 U s2 = ";
    s3.print();
}
