#include <iostream>
#include <string>

using std::string;

class Book {
public:
    Book(string name, string author, string publisher, int count, int price) {
        _name = name;
        _author = author;
        _publisher = publisher;
        _count = count;
        _price = price;
    }

    void show() const {
        std::cout << _name << "\n\t"
                  << "Author: " << _author << "\n\t"
                  << "Publisher: " << _publisher << "\n\t"
                  << "Count: " << _count << "\n\t"
                  << "Price: " << _price << std::endl;
    }

private:
    string _name;
    string _author;
    string _publisher;
    int _count;
    int _price;
};

int main() {
    Book books[3] = { Book("C++ 프로그램", "이현창", "한빛미디어", 46, 35000),
                      Book("Java", "박하대", "정인당", 25, 11000),
                      Book("HTML", "설현", "팩토리", 24, 9900) };

    for (size_t i = 0; i < 3; i++) {
        books[i].show();
    }
}
