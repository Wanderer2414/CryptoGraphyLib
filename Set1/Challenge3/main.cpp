#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include "../../include/Base/Binary/Bytes.h"
#include "../../include/Base/Binary/Hex.h"
#include "../../include/Base/Binary/Base64.h"
int main() {
    std::string in= "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    MyBase::Binary::Hex hex(in);
    MyBase::Binary::Bytes bytes(hex), out = ((~bytes)&'X') | (bytes&(~'X'));
    std::string str = out;
    std::cout << str << std::endl;
    return 0;
}