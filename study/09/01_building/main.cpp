#include <cstring>
#include <iostream>
#include <string>

using std::string;

class Building {
private:
    int _pyeong;
    char* _address = nullptr;

public:
    Building(int pyeong, const char* address) {
        _pyeong = pyeong;

        size_t len = strlen(address) + 1;
        _address = new char[len];
        strncpy(_address, address, len);
    }
    virtual ~Building() = default;

    virtual void show() = 0;

    const int& get_pyeong() const {
        return _pyeong;
    }

    const char* get_address() {
        return _address;
    }
};

class House : public Building {
private:
    int _numrooms;
    int _cost;

public:
    House(int pyeong, const char* address, int numrooms, int cost) : Building(pyeong, address) {
        _numrooms = numrooms;
        _cost = cost;
    }

    ~House() override = default;

    void show() override {
        using std::cout;
        using std::endl;

        cout << "방의 개수: " << _numrooms << endl;
        cout << "가격: " << _cost << endl;
        cout << "평수: " << get_pyeong() << endl;
        cout << "주소: " << get_address() << endl;
    }
};

class Office : public Building {
private:
    string _zonecode;
    int _rent;

public:
    Office(int pyeong, const char* address, string zonecode, int rent) : Building(pyeong, address) {
        _zonecode = std::move(zonecode);
        _rent = rent;
    }

    ~Office() override = default;

    void show() override {
        using std::cout;
        using std::endl;

        cout << "우편번호: " << _zonecode << endl;
        cout << "전세금: " << _rent << endl;
        cout << "평수: " << get_pyeong() << endl;
        cout << "주소: " << get_address() << endl;
    }
};

int main(int, char**) {
    Building* b1 = new House(32, "경기도 부천시 원미구", 4, 350000000);
    Building* b2 = new Office(24, "서울 종로구", "110-400", 250000000);
    Building* b3 = new Office(24, "인천 서구", "405-222", 200000000);

    b1->show();
    std::cout << std::endl;
    b2->show();
    std::cout << std::endl;
    b3->show();
    
    delete b1;
    delete b2;
    delete b3;
}
