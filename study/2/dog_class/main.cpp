#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Dog
{
public:
    Dog(string kind, unsigned int age, float weight)
    {
        this->kind = kind;
        this->age = age;
        this->weight = weight;
    }

    void bark() const
    {
        cout << "港港" << endl;
    }

    void use_tail() const
    {
        cout << "部府甫 抹聪促." << endl;
    }

    void show_info() const
    {
        cout
            << "Kind : " << this->kind << endl
            << "Age : " << this->age << endl
            << "Weight : " << this->weight << endl;
    }

private:
    string kind;
    unsigned int age;
    float weight;
};


int main()
{
    Dog dog_info = Dog("阂刀", 2, 1.3f);
    dog_info.show_info();
    dog_info.bark();
    dog_info.use_tail();
}
