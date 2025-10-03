#include "../../../include/Base/Binary/Bytes.h"
#include <cmath>
#include <cstring>
#include <iostream>
namespace MyBase {
    namespace Binary {
        Bytes::Bytes(char c) {
            __size = 1;
            __buffer= new unsigned char[1];
            __buffer[0] = c;
        }
        Bytes::Bytes(const std::string& text) {
            __size = text.size();
            __buffer = new unsigned char[__size];
            for (int i = 0; i<__size; i++) {
                __buffer[__size-i-1] = text[i];
            }
        }
        Bytes::Bytes(): __size(0), __buffer(0) {}

        Bytes::Bytes(const Bytes& bin) {
            __size = bin.__size;
            __buffer = new unsigned char[__size];
            memcpy(__buffer, bin.__buffer, __size);
        }
        Bytes::Bytes(Bytes&& bin) noexcept {
            __size = bin.__size;
            __buffer = bin.__buffer;

            bin.__buffer = 0;
        }
        Bytes& Bytes::operator=(const Bytes& bin) {
            if (__buffer) delete[] __buffer;

            __size = bin.__size;
            __buffer = new unsigned char[__size];
            memcpy(__buffer, bin.__buffer, __size);
            return *this;
        }

        Bytes::~Bytes() {
            if (__buffer) delete[] __buffer;
            __buffer = 0;
        }
        char Bytes::most() const {
            int count[256], max = 0;
            char c = 0;
            memset(count, 0, sizeof(int)*256);
            for (int i = 0; i<__size; i++) {
                count[__buffer[i]]++; 
                if (count[__buffer[i]]>max) {
                    max = count[__buffer[i]];
                    c = __buffer[i];
                }
            }
            return c;
        }
        Bytes Bytes::sub(const int& start, const int n) const {
            Bytes byte;
            byte.__size = n;
            byte.__buffer = new unsigned char[n];
            memcpy(byte.__buffer, __buffer + __size - start-n, n);
            return byte;
        }
        Bytes Bytes::get_seperate(const int& start, const int& distance) const {
            Bytes byte;
            byte.__size = std::floor(1.f*(__size-start-1)/distance+1);
            byte.__buffer = new unsigned char[byte.__size];
            for (int i = __size-start-1, j = byte.__size-1; i>=0; i-=distance, j--) {
                byte.__buffer[j] = __buffer[i];
            }

            return byte;
        }

        int Bytes::count() const {
            int out = 0;
            for (int i = 0; i<__size; i++) {
                char buffer = __buffer[i];
                while (buffer) {
                    out++;
                    buffer -= 1<<int(std::floor(std::log2(buffer)));
                }
            }
            return out;
        }
        int Bytes::size() const {
            return __size;
        }
        
        std::ostream& operator<<(std::ostream& out, const Bytes& bin) {
            for (int i = bin.__size-1; i>=0; i--) {
                for (int j = 7; j>=0; j--)
                    if ((bin.__buffer[i] >> j) % 2) out << '1'; else out<<'0';
                if (i) out << ' ';
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

        // ============ XOR ============

        Bytes Bytes::operator+(const Bytes& bin) const {
            Bytes out(*this);
            for (int i = out.__size-1, j = bin.__size-1; i>=0; i--, j = (j>0)?j-1:bin.__size-1) {
                out.__buffer[i] = out.__buffer[i]&(~bin.__buffer[j]) | (~out.__buffer[i])&bin.__buffer[j];
            }
            return out;
        }
        Bytes& Bytes::operator+=(const Bytes& bin) {
            for (int i = __size-1, j = bin.__size-1; i>=0; i--, j = (j>0)?j-1:bin.__size-1) {
                __buffer[i] = __buffer[i]&(~bin.__buffer[j]) | (~__buffer[i])&bin.__buffer[j];
            }
            return *this;
        }
    }
}