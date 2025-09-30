#ifndef MY_BASE_64_H
#define MY_BASE_64_H
#include <string>
#include "../Binary/Binary.h"
namespace MyBase {
    namespace Base64 {
        class Base64 {
        public:
            Base64(const Binary::Binary& binary);
            ~Base64();

            Base64(const Base64&);
            Base64(Base64&&);
            Base64& operator=(const Base64&);
            operator Binary::Binary() const;
            friend std::ostream& operator<<(std::ostream&, const Base64& hex);
        private:
            unsigned char* __buffer;
            std::size_t __size;
        };
    }
}
#endif