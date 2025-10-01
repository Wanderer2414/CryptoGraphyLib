#ifndef MY_BASE_HEX_H
#define MY_BASE_HEX_H
#include <string>
#include "Bytes.h"
namespace MyBase {
    namespace Binary {
        class Hex {
        public:
            Hex(const Binary::Bytes& binary);
            Hex(const std::string& in);
            ~Hex();

            Hex(const Hex&);
            Hex(Hex&&);
            Hex& operator=(const Hex&);
            operator Binary::Bytes() const;
            friend std::ostream& operator<<(std::ostream&, const Hex& hex);
        private:
            unsigned char* __buffer;
            int __size;
        };
    }
}
#endif