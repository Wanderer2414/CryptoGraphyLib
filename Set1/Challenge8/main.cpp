#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include "../../include/Base/Binary/Hex.h"
struct Node {
    Node* next[256];
    int count;
    Node(): count(0) {
        memset(next, 0, 256*sizeof(void*));
    };
    ~Node() {
        for (int i = 0; i<256; i++)
            if (next[i]) delete next[i];
    }
};


float MaxF(const std::string& hex);
void add(Node*& root, const int& index, const MyBase::Binary::Bytes& bytes);

int main() {
    std::ifstream fin("Set1/Challenge8/cipher.txt");
    int line = 0;
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>> q;
    std::string plaintext;
    while (!fin.eof()) {
        std::string text;
        std::getline(fin, text);
        if (line==132) plaintext = text;
        q.push({MaxF(text), line++});
    }
    for (int i = 0; i<3; i++) {
        auto couple = q.top();
        std::cout << "Line: " << couple.second << " F:" << couple.first << std::endl;
        q.pop();
    }

    return 0;
}
float MaxF(const std::string& text) {
    MyBase::Binary::Hex hex(text);
    MyBase::Binary::Bytes byte(hex);
    Node* root = 0;
    for (int i = 0; i<byte.size(); i+=16)
        add(root, 0, byte.sub(i, 16));
    float count = root->count;
    delete root;
    return count;
}


void add(Node*& root, const int& index, const MyBase::Binary::Bytes& bytes) {
    if (!root) root = new Node();
    if (index == bytes.size()) root->count++;
    else {
        add(root->next[bytes[index]], index+1, bytes);
        root->count = std::max(root->count, root->next[bytes[index]]->count);
    }
}