#include "../../../include/Base/Binary/Bytes.h"
#include <cmath>
#include <cstring>
#include <iostream>
namespace MyBase {
    namespace Binary {
        Bytes::Bytes(const std::string& text) {
            __size = text.size();
            __buffer = new unsigned char[__size];
            for (int i = 0; i<__size; i++) {
                __buffer[__size-i-1] = text[i];
            }
        }
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
            for (int i = out.__size-1, j = bin.__size-1; i>=0; i--, j = (j>0)?j-1:bin.__size-1) {
                out.__buffer[i] |= bin.__buffer[j];
            }
            return out;
        }
        Bytes& Bytes::operator|=(const Bytes& bin) {
            for (int i = __size-1, j = bin.__size-1; i>=0; i--, j = (j>0)?j-1:bin.__size-1) {
                __buffer[i] |= bin.__buffer[j];
            }
            return *this;
        }
        Bytes Bytes::operator&(const Bytes& bin) const {
            Bytes out(*this);
            for (int i = out.__size-1, j = bin.__size-1; i>=0; i--, j = (j>0)?j-1:bin.__size-1) {
                out.__buffer[i] &= bin.__buffer[j];
            }
            return out;
        }
        Bytes& Bytes::operator&=(const Bytes& bin) {
            for (int i = __size-1, j = bin.__size-1; i>=0; i--, j = (j>0)?j-1:bin.__size-1) {
                __buffer[i] &= bin.__buffer[j];
            }
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

        Bytes Bytes::operator|(const std::string& str) const {
            Bytes byte(*this);
            if (str.empty()) return byte;
            for (int i = __size-1, j=0; i>=0; i--, j=(j+1)%str.size()) {
                byte.__buffer[i] |= str[j];
            }
            return byte;
        }
        Bytes& Bytes::operator|=(const std::string& str) {
            if (str.empty()) return *this;
            for (int i = __size-1, j=0; i>=0; i--, j=(j+1)%str.size()) {
                __buffer[i] |= str[j];
            }
            return *this;
        }
        Bytes Bytes::operator&(const std::string& str) const {
            Bytes byte(*this);
            if (str.empty()) return byte;
            for (int i = __size-1, j=0; i>=0; i--, j=(j+1)%str.size()) {
                byte.__buffer[i] &= str[j];
            }
            return byte;
        }
        Bytes& Bytes::operator&=(const std::string& str) {
            if (str.empty()) return *this;
            for (int i = __size-1, j=0; i>=0; i--, j=(j+1)%str.size()) {
                __buffer[i] &= str[j];
            }
            return *this;
        }
    }
}