#include "../../include/Base/Binary/Hex.h"
#include <iostream>
#include <string>
int main() {
    std::string arr = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
    MyBase::Binary::Bytes byte(arr), code("ICE");
    byte = byte&(~code) | (~byte)&code;
    MyBase::Binary::Hex hex(byte);
    std::cout << hex << std::endl;
    return 0;
}