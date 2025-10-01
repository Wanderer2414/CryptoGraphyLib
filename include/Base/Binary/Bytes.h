#ifndef MYBASE_BINARY_H
#define MYBASE_BINARY_H
#include <ostream>
namespace MyBase {
    namespace Binary {
        class Hex;
        class Base64;
        class Bytes {
        public:
            ~Bytes();

            Bytes(const Bytes&);
            Bytes(Bytes&&);
            Bytes& operator=(const Bytes&);
            Bytes operator~() const;
            Bytes operator|(const Bytes& bin) const;
            Bytes& operator|=(const Bytes& bin);
            Bytes operator&(const Bytes& bin) const;
            Bytes& operator&=(const Bytes& bin);
            operator std::string() const;
            friend std::ostream& operator<<(std::ostream& out, const Bytes& bin);
            friend class Hex;
            friend class Base64;
        private:
            Bytes();
            unsigned char* __buffer;
            int __size;
        };
    }
}
#endif