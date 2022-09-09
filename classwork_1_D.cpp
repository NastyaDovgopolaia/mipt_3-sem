#include <iostream>
#include <limits>

int main()
{
    int size_0 = 8;
    std::cout << "type:          size         min_limit         max_limit"  << "\n";
    std::cout << "char" << ' ' << size_0 * sizeof(char) << ' ' << int(std::numeric_limits<char>::min()) << ' ' << int(std::numeric_limits<char>::max()) << "\n";
    std::cout << "short int" << ' ' << size_0 * sizeof(short int) << ' ' << std::numeric_limits<short int>::min() << ' ' << std::numeric_limits<short int>::max() << "\n";
    std::cout << "int" << ' ' << size_0 * sizeof(int) << ' ' << std::numeric_limits<int>::min() << ' ' << std::numeric_limits<int>::max() << "\n";
    std::cout << "long int" << ' ' << size_0 * sizeof(long int) << ' ' << std::numeric_limits<long int>::min() << ' ' << std::numeric_limits<long int>::max() << "\n";
    std::cout << "float" << ' ' << size_0 * sizeof(float) << ' ' << std::numeric_limits<float>::min() << ' ' << std::numeric_limits<float>::max() << "\n";
    std::cout << "double" << ' ' << size_0 * sizeof(double) << ' ' << std::numeric_limits<double>::min() << ' ' << std::numeric_limits<double>::max() << "\n";
    return 0;
}


