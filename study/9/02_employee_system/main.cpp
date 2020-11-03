#include <cstring>
#include <iostream>

using namespace std;

class Employee {
    char* _name;

public:
    explicit Employee(const char* name) {
        const auto len = strlen(name) + 1;
        _name = new char[len];
        // strncpy(_name, name, len);
        strcpy_s(_name, len, name);
    }

    virtual ~Employee() = default;

    virtual void show_salary_info() const = 0;
    virtual int get_pay() const = 0;

    void show_name() const {
        std::cout << "이름: " << _name << std::endl;
    }
};

class PermanentWorker : public Employee {
private:
    int _salary;

public:
    PermanentWorker(const char* name, const int money) : Employee(name), _salary(money) { }

    int get_pay() const override {
        return _salary;
    }

    void show_salary_info() const override {
        show_name();
        std::cout << "월급: " << get_pay() << std::endl;
    }
};

class SalesWorker : public PermanentWorker {
private:
    int _sales_result { 0 };
    double _bonus_ratio { 0.1 };

public:
    SalesWorker(const char* name, int money) : PermanentWorker(name, money) { }

    int get_pay() const override {
        const double bonus = _sales_result * _bonus_ratio;
        const int pay = PermanentWorker::get_pay() + int(bonus);
        return pay;
    }

    const SalesWorker& add_sales_result(int value) {
        _sales_result += value;
        return *this;
    }

    void show_salary_info() const override {
        show_name();
        std::cout << "월급: " << get_pay() << std::endl;
    }
};

class TemporaryWorker : public Employee {
private:
    int _work_time {};
    int _pay_per_hour;

public:
    TemporaryWorker(const char* name, int money) : Employee(name) {
        _pay_per_hour = money;
    }

    const TemporaryWorker& add_work_time(int time) {
        _work_time += time;
        return *this;
    }

    int get_pay() const override {
        return _work_time * _pay_per_hour;
    }

    void show_salary_info() const override {
        show_name();
        std::cout << "급여: " << get_pay() << std::endl;
    }
};

class EmployeeHandler {
private:
    Employee* _employees[50] {};
    int _employee_count { 0 };

public:
    const int MaxEmployees { 50 };

    EmployeeHandler() = default;

    ~EmployeeHandler() {
        for (int i = 0; i < _employee_count; ++i) {
            if (_employees[i] == nullptr) {
                delete _employees[i];
            }
        }
    }

    void add_employee(Employee* employee) {
        if (_employee_count == MaxEmployees) {
            return;
        }
        _employee_count++;
        _employees[_employee_count - 1] = employee;
    }

    void show_all_salary_info() const {
        for (int i = 0; i < _employee_count; ++i) {
            std::cout << "------------------\n";
            _employees[i]->show_salary_info();
        }
        std::cout << "------------------" << std::endl;
    }

    void ShowTotalSalary() const {
        int total { 0 };
        for (int i = 0; i < _employee_count; ++i) {
            total += _employees[i]->get_pay();
        }
        std::cout << "총 급여: " << total << std::endl;
    }
};

int main() {
    auto* employee_handler = new EmployeeHandler;

    auto* p = new PermanentWorker("정규직1", 2000000);
    employee_handler->add_employee(p);

    auto* t = new TemporaryWorker("임시직1", 7000);
    t->add_work_time(5);
    employee_handler->add_employee(t);

    auto* s = new SalesWorker("영업직1", 2100000);
    s->add_sales_result(500000);
    employee_handler->add_employee(s);

    employee_handler->show_all_salary_info();

    std::cout << std::endl;

    employee_handler->ShowTotalSalary();

    delete employee_handler;
}
