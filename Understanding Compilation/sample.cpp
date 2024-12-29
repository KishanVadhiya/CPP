#include <iostream>
#include "hello bhai.h"
// using namespace std;
// using namespace hello_bhai;
// using namespace namashkar_bhai;

void hello_bhai_ji() {
    std::cout << "Hello, Bhai Ji! in main file" << std::endl;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    hello_bhai_ji();
    namashkar_bhai::hello_bhai_ji();
    return 0;
}
