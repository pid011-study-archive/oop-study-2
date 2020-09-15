#include <iostream>
#include <string>

using std::string;

class Person
{
public:
	Person(string name, string adress, int age);
	~Person();
	const string* get_name();
	const string* get_adress();
	const int* get_age();

private:
	string name;
	string adress;
	int* age;
};

Person::Person(string name, string adress, int age)
{
	this->name = name;
	this->adress = adress;
	this->age = new int(age);
}

Person::~Person() 
{
	delete age;
}

const string* Person::get_name()
{
	return &name;
}

const string* Person::get_adress()
{
	return &adress;
}

const int* Person::get_age()
{
	return age;
}

int main()
{
	Person* p = new Person("Pilgyeong Gwak", "South Korea", 20);

	using std::cout;
	using std::endl;

	cout << "Name: " << *(p->get_name()) << endl;
	cout << "Adress: " << *(p->get_adress()) << endl;
	cout << "Age: " << *(p->get_age()) << endl;

	delete p;
}
