#include "../../include/Base/Binary/Base64.h"
#include <fstream>
#include <iostream>
#include <queue>

int main() {
    std::ifstream fin("Set1/Challenge6/bin.txt");
    std::string text;
    while (!fin.eof()) {
        std::string arr;
        std::getline(fin, arr);
        text+=arr;
    }
    fin.close();
    MyBase::Binary::Base64 base(text);
    MyBase::Binary::Bytes byte(base);
    std::priority_queue<std::pair<float, int>, std::vector<std::pair<float,int>>, std::greater<std::pair<float,int>>> q;
    for (int i = 2; i<50; i++) {
        MyBase::Binary::Bytes a(byte.sub(0, i)), b(byte.sub(i, i)), c(byte.sub(2*i, i)), d(byte.sub(3*i, i));
        float z = 1.f*(a+b).count()/i + 1.f*(a+c).count()/i + 1.f*(a+d).count()/i;
        z /= 3;
        q.push({z, i});
    }
    std::cout << "Order of hammer:" << std::endl;
    for (int i = 0 ;i<5; i++) {
        auto couple = q.top();
        q.pop();
        std::cout << couple.first << " " << couple.second << std::endl;
    }
    std::cout << "Key size: " << 29 << std::endl;
    const int keysize = 29;
    char key[keysize+1];
    key[keysize] = 0;
    for (int i = 0; i<keysize; i++) {
        MyBase::Binary::Bytes b(byte.get_seperate(i, 29));
        char c = b.most();
        c = c&(~' ') | (~c)&' ';
        key[i] = c;
    }
    std::cout << "Key: " << key << std::endl;
    MyBase::Binary::Bytes keycode(key);
    std::cout << "Plaintext: " << std::endl;
    std::cout << (std::string)(byte + keycode) << std::endl;
    return 0;
}