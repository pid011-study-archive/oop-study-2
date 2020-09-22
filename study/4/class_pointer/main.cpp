#include <iostream>

class Dog {
public:
    Dog(char* name, unsigned int age, unsigned int weight) {
        size_t len = strlen(name) + 1;
        this->name = new char[len];
        strcpy_s(this->name, len, name);

        this->age = age;
        this->weight = weight;
    }

    ~Dog() {
        delete[] name;
    }

    void show() const {
        using std::cout;
        using std::endl;

        cout << name << "\n\t"
             << "Age: " << age << "\n\t"
             << "Weight: " << weight << endl;
    }

private:
    char* name;
    unsigned int age;
    unsigned int weight;
};

int main() {
    Dog dogs[3] = {
        Dog("happy", 3, 4),
        Dog("marry", 4, 5),
        Dog("nurry", 2, 7),
    };

    Dog* dp;
    for (size_t i = 0; i < 3; i++) {
        dp = &dogs[i];

        dp->show();
    }
}
