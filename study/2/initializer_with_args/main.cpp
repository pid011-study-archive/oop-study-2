#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Information
{
public:
    Information(string name, string adress)
    {
        this->name = name;
        this->adress = adress;
    }

    string get_name()
    {
        return this->name;
    }

    string get_adress()
    {
        return this->adress;
    }

private:
    string name;
    string adress;
};

int main()
{
    Information my_info = Information("Pilgyeong Gwak", "South Korea");

    cout
        << "name : " << my_info.get_name() << endl
        << "adress : " << my_info.get_adress() << endl;
}
