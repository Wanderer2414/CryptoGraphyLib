#include "../../../include/Base/Binary/Base64.h"
#include <cmath>
#include <cstring>
#include <iostream>
namespace MyBase {
    namespace Binary {
        Base64::Base64(const Binary::Bytes& binary) {
            __size = std::ceil(1.f*binary.__size*8/6);
            __buffer = new unsigned char[__size];
            for (int i = 0, j=0; i<__size; i++, j+=6) {
                int index = j/8, remain = j%8;
                __buffer[i] = (binary.__buffer[index] >> remain) & 0x3F;
                if (remain>2 && index+1<binary.__size) 
                    __buffer[i] |= (binary.__buffer[index+1] << (8-remain)) & 0x3F;
            }
        }
        Base64::~Base64() {
            if (__buffer) delete __buffer;
        }

        Base64::Base64(const Base64& base) {
            __size = base.__size;
            __buffer = new unsigned char[__size];
            memcpy(__buffer, base.__buffer, __size);
        }
        Base64::Base64(Base64&& base) {
            __size = base.__size;
            __buffer = base.__buffer;
            base.__buffer = 0;
        }
        Base64& Base64::operator=(const Base64& base) {
            if (__buffer) delete __buffer;
            __size = base.__size;
            __buffer = new unsigned char[__size];
            memcpy(__buffer, base.__buffer, __size);
            return *this;
        }
        Base64::operator Binary::Bytes() const {
            return Binary::Bytes();
        }
        std::ostream& operator<<(std::ostream& cout, const Base64& base) {
            for (int i = base.__size-1; i>=0; i--) {
                if (base.__buffer[i]<26) cout << char(base.__buffer[i]+'A');
                else if (base.__buffer[i]<52) cout << char(base.__buffer[i]+'a' - 26);
                else if (base.__buffer[i]<62) cout << char(base.__buffer[i]+'0'-52);
                else if (base.__buffer[i] == 62) cout << '+';
                else cout << '/';
            }
            return cout;
        }
    }
}