#include <cstring>
#include <fstream>

#include <iostream>
#include <string>
#include "../../include/Base/Binary/Hex.h"
#include "../../include/Base/Binary/Base64.h"
#include "../../include/Base/Crypto/AES.h"
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
    MyBase::Crypto::AES_128 f("YELLOW SUBMARINE");
    
    char* out = new char[bytes.size()+1];
    out[bytes.size()] = 0;
    for (int i = 0; i<bytes.size(); i+=16) {
        char buffer[17];
        memset(buffer, 0, 17);
        buffer << bytes.sub(i, 16);
        f.decrypt(out+i, buffer);
    }
    std::cout << out << std::endl;
    delete[] out;
    return 0;
}