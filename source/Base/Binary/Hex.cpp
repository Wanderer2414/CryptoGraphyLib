#include <cstring>
#include <ostream>
#include <string>
#include "../../../include/Base/Binary/Hex.h"
namespace MyBase {
    namespace Binary {
        Hex::Hex(const std::string& in) {
            __size = in.size();
            __buffer = new unsigned char[__size];
            for (int i = __size-1; i>=0; i--) {
                if (in[i]>='0' && in[i]<='9') __buffer[__size-i-1] = in[i]-'0';
                else if (in[i]>='a' && in[i]<='f') __buffer[__size-i-1] = in[i] - 'a' + 10;
                else if (in[i]>='A' && in[i]<='F') __buffer[__size-i-1] = in[i] - 'A' + 10;
                else throw "Out of range hex!";
            }
        }

        Hex::Hex(const Binary::Bytes& binary) {
            __size = binary.__size*2;
            __buffer = new unsigned char[__size];
            for (int i = 0; i<binary.__size; i++) {
                __buffer[i*2] = binary.__buffer[i] & 0xF;
                __buffer[i*2+1] = binary.__buffer[i] >> 4;
            }
        }
        Hex::~Hex() {
            if (__buffer) delete[] __buffer;
        }

        Hex::Hex(const Hex& hex) {
            __size = hex.__size;
            __buffer = new unsigned char[__size];
            memcpy(__buffer, hex.__buffer, __size);
        }
        Hex::Hex(Hex&& hex) {
            __buffer = hex.__buffer;
            __size = hex.__size;
            hex.__buffer = 0;
        }
        Hex::operator Binary::Bytes() const {
            Binary::Bytes bin;
            bin.__size = __size/2 + __size%2;
            bin.__buffer = new unsigned char[bin.__size];
            for (int i = 0; i<__size; i+=2) {
                bin.__buffer[i/2] = __buffer[i];
                bin.__buffer[i/2] |= __buffer[i+1]<<4;
            }
            if (__size%2) bin.__buffer[bin.__size-1] = __buffer[__size-1];
            return bin;
        }

        Hex& Hex::operator=(const Hex& hex) {
            delete[] __buffer;
            __size = hex.__size;
            __buffer = new unsigned char[__size];
            memcpy(__buffer, hex.__buffer, __size);
            return *this;
        }

        std::ostream& operator<<(std::ostream& cout, const Hex& hex) {
            for (int i = hex.__size-1; i>=0; i--) {
                if (hex.__buffer[i]<10) cout << char(hex.__buffer[i]+'0');
                else cout << char(hex.__buffer[i] + 'A' - 10);
                if (i%2 == 0 && i!=hex.__size-1 && i) cout << ' ';
            }
            return cout;
        }
    }
}