#include "../../../include/Base/Binary/Bytes.h"
#include <cmath>
#include <cstring>
#include <iostream>
namespace MyBase {
    namespace Binary {
        Bytes::Bytes(): __size(0), __buffer(0) {}

        Bytes::~Bytes() {
            if (__buffer) delete[] __buffer;
        }

        int Bytes::size() const {
            return __size;
        }
        Bytes::Bytes(const Bytes& bin) {
            __size = bin.__size;
            __buffer = new unsigned char[__size];
            memcpy(__buffer, bin.__buffer, __size);
        }
        Bytes::Bytes(Bytes&& bin) {
            __size = bin.__size;
            __buffer = new unsigned char[__size];
            memcpy(__buffer, bin.__buffer, __size);

            bin.__buffer = 0;
        }
        Bytes& Bytes::operator=(const Bytes& bin) {
            if (__buffer) delete __buffer;

            __size = bin.__size;
            __buffer = new unsigned char[__size];
            memcpy(__buffer, bin.__buffer, __size);
            return *this;
        }
        std::ostream& operator<<(std::ostream& out, const Bytes& bin) {
            for (int i = bin.__size-1; i>=0; i--) {
                for (int j = 7; j>=0; j--)
                    if ((bin.__buffer[i] >> j) % 2) out << '1'; else out<<'0';
            }
            return out;
        }

        Bytes Bytes::operator~() const {
            Bytes bin(*this);
            for (int i = 0; i<__size; i++) bin.__buffer[i] = ~bin.__buffer[i];
            return bin;
        }
        Bytes Bytes::operator|(const Bytes& bin) const {
            Bytes out(*this);
            for (int i = 0; i<__size; i++) out.__buffer[i] |= bin.__buffer[i];
            return out;
        }
        Bytes& Bytes::operator|=(const Bytes& bin) {
            for (int i = 0; i<__size; i++) __buffer[i] |= bin.__buffer[i];
            return *this;
        }
        Bytes Bytes::operator&(const Bytes& bin) const {
            Bytes out(*this);
            for (int i = 0; i<__size; i++) out.__buffer[i] &= bin.__buffer[i];
            return out;
        }
        Bytes& Bytes::operator&=(const Bytes& bin) {
            for (int i = 0; i<__size; i++) __buffer[i] |= bin.__buffer[i];
            return *this;
        }
        Bytes::operator std::string() const {
            std::string out;
            out.resize(__size);
            for (int i = 0; i<__size; i++) out[i] = __buffer[__size-i-1];
            return out;
        }

        Bytes Bytes::operator|(char c) const {
            Bytes byte(*this);
            for (int i = 0; i<__size; i++) byte.__buffer[i] |= c;
            return byte;
        }
        Bytes& Bytes::operator|=(char c) {
            for (int i = 0; i<__size; i++) __buffer[i] |= c;
            return *this;
        }
        Bytes Bytes::operator&(char c) const {
            Bytes byte(*this);
            for (int i = 0; i<__size; i++) byte.__buffer[i] &= c;
            return byte;
        }
        Bytes& Bytes::operator&=(char c) {
            Bytes byte(*this);
            for (int i = 0; i<__size; i++) byte.__buffer[i] &= c;
            return *this;
        }

        unsigned char& Bytes::operator[](const int& index) {
            return __buffer[__size - index - 1];
        }
        const unsigned char& Bytes::operator[](const int& index) const {
            return __buffer[__size - index - 1];
        }
    }
}