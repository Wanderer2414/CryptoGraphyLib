#ifndef MYBASE_BINARY_H
#define MYBASE_BINARY_H
#include <ostream>
namespace MyBase {
    namespace Hexadecimal {
        class Hex;
    }
    namespace Base64 {
        class Base64;
    }
    namespace Binary {
        class Binary {
        public:
            Binary(const char& c);
            Binary(int integer);
            ~Binary();

            Binary(const Binary&);
            Binary(Binary&&);
            Binary& operator=(const Binary&);
            friend std::ostream& operator<<(std::ostream& out, const Binary& bin);
            friend class Hexadecimal::Hex;
            friend class Base64::Base64;
        private:
            Binary();
            unsigned char* __buffer;
            int __size;
        };
    }
}
#endif