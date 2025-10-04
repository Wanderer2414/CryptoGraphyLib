#include <fstream>

#include <iostream>
#include <string>
#include "../../include/Base/Binary/Hex.h"
#include "../../include/Base/Crypto/AES.h"
int main() {
    // std::ifstream fin("Set1/Challenge7/cipher.txt");
    // std::string text;
    // while (!fin.eof()) {
    //     std::string line;
    //     std::getline(fin, line);
    //     text += line;
    // }
    // fin.close();
    // MyBase::Binary::Base64 base(text);
    // MyBase::Binary::Bytes bytes(base);
    // for (int i = 0; i<bytes.size(); i+=16) {
    //     char buffer[16];
    //     buffer << bytes.sub(i, 16);

    // }
    std::string key = "YELLOW SUBMARINE";
    // MyBase::Binary::Hex keyh(key);
    // MyBase::Binary::Bytes bytes(keyh);
    // std::string data(bytes);
    MyBase::Crypto::AES_128 f(key.data());

    // MyBase::Binary::Hex texth("3243f6a8885a308d313198a2e0370734");
    // bytes = MyBase::Binary::Bytes(texth);
    // std::string text(bytes);
    char out[17];
    out[16] = 0;
    f.encrypt(key.data(), out);
    
    MyBase::Binary::Bytes bytes = MyBase::Binary::Bytes(out);
    MyBase::Binary::Hex hex(bytes);
    std::cout << hex << std::endl;
    return 0;
}