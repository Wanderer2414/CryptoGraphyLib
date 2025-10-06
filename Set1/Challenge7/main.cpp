#include <cstring>
#include <fstream>

#include <iostream>
#include <string>
#include "../../include/Base/Binary/Hex.h"
#include "../../include/Base/Binary/Base64.h"
#include "../../include/Base/Crypto/AES.h"
#include "../../include/Base/Crypto/ModeECB.h"
int main() {
    std::ifstream fin("Set1/Challenge7/cipher.txt");
    std::string text;
    while (!fin.eof()) {
        std::string line;
        std::getline(fin, line);
        text += line;
    }
    fin.close();
    MyBase::Binary::Base64 base(text);
    MyBase::Binary::Bytes bytes(base);
    MyBase::Crypto::ECB_128 mode;
    MyBase::Crypto::AES_128 f("YELLOW SUBMARINE", &mode);
    
    std::string out = f.decrypt(bytes);

    std::cout << out << std::endl;
    return 0;
}