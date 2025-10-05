#include "../../../include/Base/Binary/Base64.h"
#include <cmath>
#include <cstring>
#include <iostream>
#include <stdexcept>
namespace MyBase {
    namespace Binary {
        Base64::Base64(const Binary::Bytes& binary) {
            __size = std::ceil(1.f*binary.__size/3)*4;
            __buffer = new unsigned char[__size];
            memset(__buffer,0,__size);

            int offset = binary.__size%3;
            if (offset) {
                offset ^= 3;
                memset(__buffer, 255, offset);
            }

            int j = offset*8;
            for (int i = 0; i<binary.__size; i++) {
                int index = j/6, sub_index = j%6;
                __buffer[index] |= (binary.__buffer[i]<<sub_index) & 0x3F;
                __buffer[index+1] |= binary.__buffer[i] >> (6-sub_index);
                j+=8;
            }
        }
        Base64::Base64(const std::string& text) {
            __size = text.size();
            while (__size%4!=0) __size++;
            __buffer = new unsigned char[__size];
            for (int i = 0; i<text.size(); i++) {
                if (text[i] >= 'A' && text[i]<='Z') __buffer[__size-i-1] = text[i]-'A';
                else if (text[i]>='a' && text[i] <='z') __buffer[__size-i-1] = text[i]-'a'+26;
                else if (text[i]>='0' && text[i]<='9') __buffer[__size-i-1] = text[i]-'0'+52;
                else if (text[i]=='+') __buffer[__size-i-1] = 62;
                else if (text[i] == '/') __buffer[__size-i-1] = 63;
                else if (text[i] == '=') __buffer[__size-i-1] = 255;
                else throw std::runtime_error("Out range of base64!");
            }
            for (int i = text.size(); i<__size; i++) __buffer[__size-i-1] = 255;
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
            Bytes bytes;
            int offset = 0;
            while (__buffer[offset]==255) offset++;

            bytes.__size = __size*3/4;
            if (offset == 2) bytes.__size--;

            bytes.__buffer = new unsigned char[bytes.__size];
            memset(bytes.__buffer, 0, bytes.__size);

            int request = 8, j = 0;
            if (offset==1) request = 2;
            else if (offset == 2) request = 4;

            for (int i = offset; i<__size; i++) {
                bytes.__buffer[j] |= __buffer[i]<<(8-request);
                if (request<8) bytes.__buffer[j+1] |= __buffer[i]>>request;
                request-=6;
                if (request<=0) {
                    request += 8;
                    j++;
                }
            }
            return bytes;
        }
        std::ostream& operator<<(std::ostream& cout, const Base64& base) {
            for (int i = base.__size-1; i>=0; i--) {
                if (base.__buffer[i]<26) cout << char(base.__buffer[i]+'A');
                else if (base.__buffer[i]<52) cout << char(base.__buffer[i]+'a' - 26);
                else if (base.__buffer[i]<62) cout << char(base.__buffer[i]+'0'-52);
                else if (base.__buffer[i] == 62) cout << '+';
                else if (base.__buffer[i] == 255) cout << '=';
                else cout << '/';
            }
            return cout;
        }
    }
}