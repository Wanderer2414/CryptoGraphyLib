#ifndef MY_BASE_64_H
#define MY_BASE_64_H
#include <string>
#include "Bytes.h"
namespace MyBase {
    namespace Binary {
        class Base64 {
        public:
            Base64(const Binary::Bytes& binary);
            ~Base64();

            Base64(const Base64&);
            Base64(Base64&&);
            Base64& operator=(const Base64&);
            operator Binary::Bytes() const;
            friend std::ostream& operator<<(std::ostream&, const Base64& hex);
        private:
            unsigned char* __buffer;
            int __size;
        };
    }
}
#endif