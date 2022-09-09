#include <iostream>
#include <cmath>

using namespace std;

int comparator(void* a, void* b){
    int* int_a = reinterpret_cast<int*>(a);
    int* int_b = reinterpret_cast<int*>(b);
    if (*int_a < *int_b){
        return -1;
    }
    if (*int_a > *int_b){
        return 1;
    }
    return 0;
}

int mini(void* arr, int arr_size, int type_size, int (*compare)(void*, void*)){
   int minimum = 0;
   unsigned char* char_arr = reinterpret_cast<unsigned char*>(arr);

   for (int i = 1; i < arr_size; i++){
     if (compare(char_arr + i*type_size, char_arr + minimum * type_size) < 0){
        minimum = i;
     }
   }
   return minimum;
}


int main() {

  int arr[4] = {4, 7, 2, 9};

  cout << mini(arr, 4, sizeof(int), comparator) << endl;

  return 0;
}
