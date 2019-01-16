#include <iostream>
#include "Messenger.h"
#include "Singleton.h"

int main() {
    MyClass& m = MyClass::instance();
    m.setData(10);
    std::cout<< m.getData();
    return 0;
}
