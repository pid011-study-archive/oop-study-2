#include <cstring>
#include <iostream>

class MyFriendInfo {
private:
    char* _name;
    int _age;

public:
    MyFriendInfo(const char* name, int age) {
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);
        _age = age;
    }
    ~MyFriendInfo() {
        delete[] _name;
    }

    const char* get_name() const {
        return _name;
    }

    int get_age() const {
        return _age;
    }
};

class MyFriendDetailInfo : public MyFriendInfo {
private:
    char* _adress;
    char* _phone_number;

public:
    MyFriendDetailInfo(const char* name, int age, const char* adress, const char* phone_number)
        : MyFriendInfo(name, age) {
        _adress = new char[strlen(adress) + 1];
        strcpy(_adress, adress);

        _phone_number = new char[strlen(phone_number) + 1];
        strcpy(_phone_number, phone_number);
    }
    ~MyFriendDetailInfo() {
        delete[] _adress;
        delete[] _phone_number;
    }

    const char* get_adress() const {
        return _adress;
    }

    const char* get_phone_number() const {
        return _phone_number;
    }
};

void show_info(MyFriendDetailInfo& info) {
    using std::cout;
    using std::endl;

    cout << "이름: " << info.get_name() << endl;
    cout << "나이: " << info.get_age() << endl;
    cout << "주소: " << info.get_adress() << endl;
    cout << "전화번호: " << info.get_phone_number() << endl;
}

int main(int, char**) {
    MyFriendDetailInfo a("김국진", 24, "경기도이천", "010-3423-3330");
    MyFriendDetailInfo b("이수경", 22, "서울 서초구", "010-3539-9458");

    show_info(a);
    std::cout << std::endl;
    show_info(b);
}
