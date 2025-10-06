#include <iostream>
#include <string>
#include "../../include/Base/PKCS#7/Pad.h"
int main() {
    std::string in("YELLOW SUBMARINE");
    std::string out = MyBase::PKCS_7::pad(in, 4, 20);
    for (int i = 0; i<20 ; i++) std::cout << (int)out[i] << " ";
    return 0;
}