
#include <fstream>
#include <iostream>
int main() {
    std::ifstream fia("cat.png", std::ios::binary | std::ios::in);
    std::ifstream fib("ciphercat.png", std::ios::binary | std::ios::in);
    fia.seekg(0, std::ios::end);
    fib.seekg(0, std::ios::end);
    int size = fia.tellg();
    fia.seekg(0); fib.seekg(0);
    char* bufferA = new char[size], *bufferB = new char[size];
    fia.read(bufferA, size);
    fib.read(bufferB, size);
    char* bufferO = new char[size];
    for (int i = 0; i<size; i++) {
        bufferO[i] = bufferA[i]&(~bufferB[i]) | (~bufferA[i]&bufferB[i]);
    }
    delete[] bufferA;
    delete[] bufferB;
    fia.close();
    fib.close();
    std::cout << std::endl;
    std::cout << bufferO << std::endl;
    delete[] bufferO;
    return 0;
}