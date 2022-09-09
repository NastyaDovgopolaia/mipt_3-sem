
#include <iostream>
#include <cstring>

using namespace std;

void Swap(void *a, void *b, int Size)
{
    void *sth = malloc(Size);
    memcpy(sth, a, Size);
    memcpy(a, b, Size);
    memcpy(b, sth, Size);
    free(sth);
}

int main()
{
    char a = 0, b = 0;
    cin >> a >> b;
    Swap(&a, &b, sizeof(char));
    cout << a << " " << b;
    return 0;
}
