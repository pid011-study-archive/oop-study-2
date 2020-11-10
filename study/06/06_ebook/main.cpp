#include <cstring>
#include <iostream>

class Book {
private:
    char* _title;
    char* _isbn;
    int _price;

public:
    Book(const char* title, const char* isbn, int price)
        : _price(price) {
        _title = new char[strlen(title) + 1];
        strcpy(_title, title);

        _isbn = new char[strlen(isbn) + 1];
        strcpy(_isbn, isbn);
    }

    ~Book() {
        delete[] _title;
        delete[] _isbn;
    }

    void show_book_info() const {
        using namespace std;

        cout << "제목: " << _title << endl;
        cout << "ISBN: " << _isbn << endl;
        cout << "가격: " << _price << endl;
    }
};

class EBook : protected Book {
private:
    char* _drm_key;

public:
    EBook(const char* title, const char* isbn, int price, const char* drm_key)
        : Book(title, isbn, price) {
        _drm_key = new char[strlen(drm_key) + 1];
        strcpy(_drm_key, drm_key);
    }

    ~EBook() {
        delete[] _drm_key;
    }

    void show_book_info() const {
        using namespace std;

        EBook::show_book_info();
        cout << "DRM KEY: " << _drm_key << endl;
    }
};

int main(int, char**) {
    Book book("C++ 프로그램", "123-456-789", 12000);
    book.show_book_info();
    std::cout << std::endl;
    EBook ebook("C++ 프로그램 E-Book", "123-6755-123-4325", 10000, "2349gd3");
    ebook.show_book_info();
}
