#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

class Book {
    char* _title{nullptr};
    char* _isbn{nullptr};
    int _price{0};

    void set_title(const char* value) {
        delete[] _title;
        size_t title_len = strlen(value) + 1;
        _title = new char[title_len];
        strncpy(_title, value, title_len);
    }

    void set_isbn(const char* value) {
        delete[] _isbn;
        size_t isbn_len = strlen(value) + 1;
        _isbn = new char[isbn_len];
        strncpy(_isbn, value, isbn_len);
    }

public:
    Book(const char* title, const char* isbn, int price) : _price(price) {
        set_title(title);
        set_isbn(isbn);
    }

    Book(const Book& copy) {
        set_title(copy._title);
        set_isbn(copy._isbn);
        _price = copy._price;
    }

    virtual ~Book() {
        delete[] _title;
        delete[] _isbn;
    }

    virtual void show_book_info() {
        cout << "Title: " << title() << endl;
        cout << "ISBN: " << isbn() << endl;
        cout << "Price: " << price() << endl;
    }

    const char* title() const {
        return _title;
    }

    const char* isbn() const {
        return _isbn;
    }

    int price() const {
        return _price;
    }

    Book& operator=(const Book& copy) {
        set_title(copy._title);
        set_isbn(copy._isbn);
        _price = copy._price;

        return *this;
    }
};

class Ebook : public Book {
    char* _drm_key{nullptr};

    void set_drm_key(const char* value) {
        delete[] _drm_key;
        size_t drm_key_len = strlen(value) + 1;
        _drm_key = new char[drm_key_len];
        strncpy(_drm_key, value, drm_key_len);
    }

public:
    Ebook(const char* title, const char* isbn, int price, const char* drm_key)
        : Book(title, isbn, price) {
        set_drm_key(drm_key);
    }

    Ebook(const Ebook& copy) : Book(copy) {
        set_drm_key(copy._drm_key);
    }

    virtual ~Ebook() {
        delete[] _drm_key;
    }

    virtual void show_book_info() override {
        Book::show_book_info();
        cout << "DRM Key: " << drm_key() << endl;
    }

    const char* drm_key() const {
        return _drm_key;
    }

    Ebook& operator=(const Ebook& copy) {
        Book::operator=(copy);
        set_drm_key(copy._drm_key);

        return *this;
    }
};

int main() {
    Ebook ebook1("C++ 프로그램 ebook", "555-12345-890-1", 10000, "fdx98dfx");
    Ebook ebook2 = ebook1;
    ebook2.show_book_info();
    cout << endl;
    Ebook ebook3("dummy", "dummy", 0, "dummy");
    ebook3 = ebook2;
    ebook3.show_book_info();
}

/*
Title: C++ 프로그램 ebook
ISBN: 555-12345-890-1
Price: 10000
DRM Key: fdx98dfx

Title: C++ 프로그램 ebook
ISBN: 555-12345-890-1
Price: 10000
DRM Key: fdx98dfx
*/
