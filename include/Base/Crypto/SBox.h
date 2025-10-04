#ifndef S_BOX_H
#define S_BOX_H
namespace MyBase {
    namespace Crypto {
        namespace SBox {
            char get(char c);
            unsigned char get(unsigned char c);
            unsigned char rev(unsigned char c);
            unsigned int get(const unsigned int& value);
        }
    }
}
#endif