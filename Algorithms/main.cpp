#include <iostream>

using namespace std;

int main() {
    int A[] = { 5, 7, 1, 4, 8, 0 };

    for(const auto &a : A)
        cout << a << " ";
    return 0;
}
