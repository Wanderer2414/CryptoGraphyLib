#include "../../../include/Base/Binary/Binary.h"
#include <cmath>
#include <cstring>
#include <iostream>
namespace MyBase {
    namespace Binary {
        Binary::Binary(): __size(0), __buffer(0) {}

        Binary::Binary(const char& c) {
            __size = 1;
            __buffer = new unsigned char[__size];
            __buffer[0] = c;
        }
        Binary::Binary(int integer) {
            int size = 0;
            if (integer) size = std::ceil(std::log2(std::abs(integer)));
            if (integer<0) size++;
            
            __size = std::ceil(0.125f*size);
            __buffer = new unsigned char[__size];
            for (int i = __size-1; i>=0 ;i--) {
                __buffer[i] = integer & 0xFF;
                integer >>= 8;
            }
        }
        Binary::~Binary() {
            if (__buffer) delete[] __buffer;
        }

        Binary::Binary(const Binary& bin) {
            __size = bin.__size;
            __buffer = new unsigned char[__size];
            memcpy(__buffer, bin.__buffer, __size);
        }
        Binary::Binary(Binary&& bin) {
            __size = bin.__size;
            __buffer = new unsigned char[__size];
            memcpy(__buffer, bin.__buffer, __size);

            bin.__buffer = 0;
        }
        Binary& Binary::operator=(const Binary& bin) {
            if (__buffer) delete __buffer;

            __size = bin.__size;
            __buffer = new unsigned char[__size];
            memcpy(__buffer, bin.__buffer, __size);
            return *this;
        }
        std::ostream& operator<<(std::ostream& out, const Binary& bin) {
            for (int i = 0; i<bin.__size; i++) {
                for (int j = 7; j>=0; j--)
                    if ((bin.__buffer[i] >> j) % 2) out << '1'; else out<<'0';
            }
            return out;
        }

        Binary Binary::operator~() const {
            Binary bin(*this);
            for (int i = 0; i<__size; i++) bin.__buffer[i] = ~bin.__buffer[i];
            return bin;
        }
        Binary Binary::operator|(const Binary& bin) const {
            Binary out(*this);
            for (int i = 0; i<__size; i++) out.__buffer[i] |= bin.__buffer[i];
            return out;
        }
        Binary& Binary::operator|=(const Binary& bin) {
            for (int i = 0; i<__size; i++) __buffer[i] |= bin.__buffer[i];
            return *this;
        }
        Binary Binary::operator&(const Binary& bin) const {
            Binary out(*this);
            for (int i = 0; i<__size; i++) out.__buffer[i] &= bin.__buffer[i];
            return out;
        }
        Binary& Binary::operator&=(const Binary& bin) {
            for (int i = 0; i<__size; i++) __buffer[i] |= bin.__buffer[i];
            return *this;
        }
    }
}