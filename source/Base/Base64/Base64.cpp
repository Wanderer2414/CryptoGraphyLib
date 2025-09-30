#include "../../../include/Base/Base64/Base64.h"
#include <cmath>
#include <cstring>
#include <iostream>
namespace MyBase {
    namespace Base64 {
        Base64::Base64(const Binary::Binary& binary) {
            __size = std::ceil(1.f*binary.__size*8/6);
            __buffer = new unsigned char[__size];
            for (int i = __size-1, j = binary.__size*8-6; i>=0; i--, j-=6) {
                if (j>=0) {
                    char remain = j%8-2;
                    int index = j/8;
                    __buffer[i] = binary.__buffer[index];
                    if (remain>0) __buffer[i] = binary.__buffer[index]<<remain | (binary.__buffer[index+1]>>(8-remain));
                    else __buffer[i] >>= -remain;
                    __buffer[i] &= 0x3F;
                }
                else if (-j<6) __buffer[i] = binary.__buffer[0]>>(2-j);
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
        Base64::operator Binary::Binary() const {
            return Binary::Binary();
        }
        std::ostream& operator<<(std::ostream& cout, const Base64& base) {
            for (int i = 0; i<base.__size; i++) {
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