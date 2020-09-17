#include <iostream>
#include <string>

namespace MonsterWorld {
    using std::string;

    class Canvas {
    public:
        enum class State { Fill, Empty };

        Canvas(int length) {
            map           = new string[length];
            canvas_length = length;

            clear();
        }

        ~Canvas() { delete[] map; }

        void clear() {
            for (int i = 0; i < canvas_length; i++) {
                map[i].clear();
                for (int j = 0; j < canvas_length; j++) {
                    map[i].append(fill_element);
                }
            }
        }

        void draw(int x, int y, State change) {
            if (x < 0 || x > canvas_length - 1 || y < 0 || y > canvas_length - 1) {
                return;
            }
            string target = empty_element;

            switch (change) {
            case State::Fill:
                target = fill_element;
                break;
            case State::Empty:
                target = empty_element;
                break;
            }

            map[y].replace(x, 1, target);
        }

        string get_full_map() const {
            string full_map {};
            for (int i = 0; i < canvas_length; i++) {
                for (int j = 0; j < canvas_length; j++) {
                    full_map.append(string(1, map[i][j]) + (j < canvas_length - 1 ? " " : ""));
                }
                full_map.append(i < canvas_length - 1 ? "\n" : "");
            }
            return full_map;
        }

    private:
        // 특수문자를 쓰게 될 경우 char 로 값을 가져오지 못하므로 ACII 내에 존재하는 문자를 쓰는게 좋을듯

        const string fill_element  = "B";
        const string empty_element = " ";

        int canvas_length;

        // map array
        // contains each line with string type
        string* map;
    };
}

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    using namespace MonsterWorld;
    Canvas* canvas = new Canvas(10);

    cout << "캔버스" << endl;
    cout << canvas->get_full_map() << endl << endl;
    canvas->draw(4, 5, Canvas::State::Empty);
    cout << canvas->get_full_map() << endl;

    delete canvas;
}
