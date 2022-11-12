#include <iostream>

using namespace std;

class Matrix {
    private:
        int** mat;
        int Size;
    public:
        Matrix(int arr[], int n_elements) {
            this->Size = n_elements;
            this->mat = new int*[n_elements];
            for (int i = 0; i < n_elements; i++) {
                mat[i] =  new int[n_elements];
            }

            int k = 0;

            for (int i = 0; i < n_elements; i++) {
                for (int j = 0; j < n_elements; j++) {
                    mat[i][j] = arr[k];
                    k++;
                }
            }
        }

        Matrix(int element, size_t n_elements) {
            this->Size = n_elements;
            this->mat = new int*[n_elements];
            for (int i = 0; i < n_elements; i++) {
                this->mat[i] =  new int[n_elements];
            }

            for (int i = 0; i < n_elements; i++) {
                for (int j = 0; j < n_elements; j++) {
                    mat[i][j] = element;
                }
            }
        }

        Matrix() {
            this->Size = 1;
            this->mat = new int*[1];
            for (int i = 0; i < 1; i++) {
                mat[i] =  new int[1];
            }
            mat[0][0] = 1;
        }

        Matrix(const Matrix& other) {
            this->Size = other.Size;
            this->mat = new int*[other.Size];
            for (int i = 0; i < other.Size; i++) {
                this->mat[i] =  new int[other.Size];
            }
            for (int i = 0; i < other.Size; i++) {
                for (int j = 0; j < other.Size; j++) {
                    this->mat[i][j] = other.mat[i][j];
                }
            }

        }

        void printMatrix() {
            for (int i = 0; i < Size; i++) {
                for (int j = 0; j < Size; j++) {
                    cout << mat[i][j] << "\t";
                }
                cout << endl;
            }
        }
        int calcDeterminant(){
            if (Size == 1){
                return mat[0][0];
            }

            int det = 0;

            for (int i = 0; i < Size; i++){

                int *temp_arr = new int [Size - 1];
                int position = 0;

                for(int j = 1; j < Size; j++){
                    for (int k = 0; k < Size; k++){
                        if (k != i){
                            temp_arr[position] = mat[j][k];
                            position++;
                        }
                    }
                }

                Matrix temp_Mat = Matrix(temp_arr, (Size - 1));

                if (i % 2 == 0){
                    det += temp_Mat.calcDeterminant() * mat[0][i];
                }
                else{
                    det -= temp_Mat.calcDeterminant() * mat[0][i];
                }

                delete [] temp_arr;
            }

            return det;
        }
        void calcSquare(){
            int* temp_arr = new int [Size];

            for (int i1 = 0; i1 < Size * Size; i1++){
                temp_arr[i1] = 0;

                int i = i1 / Size;
                int j = i1 % Size;

                for (int k = 0; k < Size; k++) {
                    temp_arr[i1] += mat[i][k] * mat[k][j];
                }
            }

            Matrix temp_Mat = Matrix (temp_arr, Size);

           for (int i = 0; i < Size; i++){
                for (int j = 0; j < Size; j++){
                    this->mat[i][j] = temp_Mat.mat[i][j];
                }
           }

            delete [] temp_arr;
        }

        void Transpose(){
            Matrix base = *this;

            for (int i = 0; i < Size; i++){
                for (int j = 0; j < Size; j++){
                    this->mat[i][j] = base.mat[j][i];
                }
            }
        }

        ~ Matrix(){
            for (int i = 0; i < Size; i++){
                delete [] mat[i];
            }

            delete [] mat;
        }

};


