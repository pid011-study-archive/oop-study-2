#include <iostream>

using namespace std;

class Information
{
public:
    Information(string id, string name, int korean_score, int english_score)
    {
        this->id = id;
        this->name = name;
        this->korean_score = korean_score;
        this->english_score = english_score;
    }

    string get_id()
    {
        return id;
    }

    string get_name()
    {
        return name;
    }

    int get_korean_score()
    {
        return korean_score;
    }

    int get_english_score()
    {
        return english_score;
    }

private:
    string id;
    string name;
    int korean_score;
    int english_score;
};

int main()
{
    Information* iu = new Information("1234564", "아이유", 98, 100);

    cout << "학번 : " << iu->get_id() << endl;
    cout << "이름 : " << iu->get_name() << endl;
    cout << "국어 : " << iu->get_korean_score() << endl;
    cout << "영어 : " << iu->get_english_score() << endl;

    delete iu;
}
