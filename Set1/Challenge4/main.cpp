#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "../../include/Base/Binary/Hex.h"
int main() {
    std::ifstream fin("Set1/Challenge4/input.txt");
    while (!fin.eof()) {
        std::string buffer;
        std::getline(fin, buffer);
        MyBase::Binary::Hex hex(buffer);
        MyBase::Binary::Bytes byte(hex);
    
        int count[256], max = 0;
        unsigned char highest = 0;
        memset(count, 0, sizeof(int)*256);
        for (int i = 0; i<byte.size(); i++) {
            count[byte[i]]++;
            if (count[byte[i]]>max) {
                max = count[byte[i]];
                highest = byte[i];
            }
        }
        if (max>4) {
            char c = highest&(~32) | (~highest)&32;
            byte = (~byte)&c | byte&(~c);
            std::cout << buffer << " " << (std::string)byte << std::endl;
        }
    }
    fin.close();
    return 0;
}