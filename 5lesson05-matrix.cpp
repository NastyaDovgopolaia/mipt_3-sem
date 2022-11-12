#include <iostream>

using namespace std;

template<typename Field, size_t M, size_t N>
class Matrix {
private:
    Field Mat[M][N];
public:
    Matrix(Field ** Mat) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++)
                this->Mat[i][j] = Mat[i][j];
        }
    }

    void print() {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++)
                cout << this->Mat[i][j] << "\t";
            cout << endl;
        }
    }
    Matrix& operator+=(const Matrix& other) {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                this->Mat[i][j] += other.Mat[i][j];
        return *this;
    }
    Matrix& operator-=(const Matrix& other) {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                this-Mat[i][j] -= other.Mat[i][j];
        return *this;
    }
    Matrix operator*(int T) {
        Matrix mult;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                this->Mat[i][j] = T*this->Mat[i][j];
        return *this;
    }
};

int main() {

    return 0;


}
