#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>

using namespace std;

class House {
private:
    char* name;  //이름
    char* addr;  //주소
    char* phone; //전화번호
public:
    House(const char* name, const char* addr, const char* phone) {
        // name 초기화
        size_t name_len = strlen(name) + 1;
        this->name = new char[name_len];
        strncpy(this->name, name, name_len);

        // addr 초기화
        size_t addr_len = strlen(addr) + 1;
        this->addr = new char[addr_len];
        strncpy(this->addr, addr, addr_len);

        // phone 초기화
        size_t phone_len = strlen(phone) + 1;
        this->phone = new char[phone_len];
        strncpy(this->phone, phone, phone_len);
    }

    House(const House& copy) {
        // name 복사
        size_t name_len = strlen(copy.name) + 1;
        this->name = new char[name_len];
        strncpy(this->name, copy.name, name_len);

        // addr 복사
        size_t addr_len = strlen(copy.addr) + 1;
        this->addr = new char[addr_len];
        strncpy(this->addr, copy.addr, addr_len);

        // phone 복사
        size_t phone_len = strlen(copy.phone) + 1;
        this->phone = new char[phone_len];
        strncpy(this->phone, copy.phone, phone_len);
    }

    ~House() {
        delete[] name;
        delete[] addr;
        delete[] phone;
    }

    void ShowData() const {
        cout << "이름: " << this->name << endl;
        cout << "주소: " << this->addr << endl;
        cout << "전화번호: " << this->phone << endl;
    }

    void ChangePhone(const char* phone) {
        // phone 데이터를 지우고 다시 복사
        delete[] this->phone;
        size_t phone_len = strlen(phone) + 1;
        this->phone = new char[phone_len];
        strncpy(this->phone, phone, phone_len);
    }
};
int main() {
    House h1("홍길동", "서울시 종로구", "02-341-2344");
    House h2 = h1;
    cout << "********* 변경 전 *********" << endl;
    h1.ShowData();
    h2.ShowData();
    h1.ChangePhone("010-234-5678"); //전화번호 변경 함수
    cout << "********* 변경 후 *********" << endl;
    h1.ShowData();
    h2.ShowData();
    return 0;
}
