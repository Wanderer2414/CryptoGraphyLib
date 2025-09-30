#include <cstring>
#include <iostream>
#include <string>
#include "include/Base/Binary/Binary.h"
#include "include/Base/Hexadecimal/Hex.h"
#include "include/Base/Base64/Base64.h"
int main() {
    std::string in;
    std::getline(std::cin, in);
    MyBase::Hexadecimal::Hex hex(in);
    MyBase::Base64::Base64 base(hex);
    std::cout << base << std::endl;
    return 0;
}