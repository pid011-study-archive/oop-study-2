#include <iostream>
#include <cstdlib>
#include <ctime>

class Matrix {
public:
    Matrix(int row, int col) {
        srand((unsigned)time(NULL));

        _row = row;
        _col = col;

        _mat = new int*[col];
        for (size_t i = 0; i < col; i++) {
            _mat[i] = new int[row];
        }
    }

    ~Matrix() {
        for (size_t i = 0; i < _col; i++) {
            delete[] _mat[i];
        }
        delete[] _mat;
    }

    void set_rand() {
        for (size_t i = 0; i < _col; i++) {
            for (size_t j = 0; j < _row; j++) {
                _mat[i][j] = rand() % 9 + 1;
            }
        }
    }

    void print() const {
        for (int i = 0; i < _col; i++) {
            for (int j = 0; j < _row; j++) {
                std::cout << _mat[i][j] << (j < _row - 1 ? ' ' : '\n');
            }
        }

        std::cout << std::endl;
    }

private:
    int _row;
    int _col;
    int** _mat;
};


int main() {
    Matrix u(12, 3);
    u.set_rand();
    u.print();
}
