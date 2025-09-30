#ifndef MY_BASE_HEX_H
#define MY_BASE_HEX_H
#include <string>
#include "../Binary/Binary.h"
namespace MyBase {
    namespace Hexadecimal {
        class Hex {
        public:
            Hex(const Binary::Binary& binary);
            Hex(const std::string& in);
            ~Hex();

            Hex(const Hex&);
            Hex(Hex&&);
            Hex& operator=(const Hex&);
            operator Binary::Binary() const;
            friend std::ostream& operator<<(std::ostream&, const Hex& hex);
        private:
            unsigned char* __buffer;
            std::size_t __size;
        };
    }
}
#endif