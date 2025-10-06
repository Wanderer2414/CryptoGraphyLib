#include <fstream>
#include <iostream>
#include "../../include/Base/Binary/Base64.h"
#include "../../include/Base/Crypto/ModeCBC.h"
#include "../../include/Base/Crypto/AES.h"
int main() {
    std::ifstream fin("Set2/Challenge2/cipher.txt");
    std::string text;
    while (!fin.eof()) {
        std::string line;
        std::getline(fin, line);
        text += line;
    }
    fin.close();

    MyBase::Binary::Base64 base(text);
    MyBase::Binary::Bytes byte(base);
    MyBase::Crypto::CBC_128 mode;
    MyBase::Crypto::AES_128 f("YELLOW SUBMARINE", &mode);
    std::string plaintext = f.decrypt(byte);
    std::cout << plaintext << std::endl;
    return 0;
}