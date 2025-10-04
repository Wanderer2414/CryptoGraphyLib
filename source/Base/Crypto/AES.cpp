#include "../../../include/Base/Crypto/AES.h"
#include "../../../include/Base/Crypto/SBox.h"
#include "../../../include/Base/Binary/Hex.h"
#include <cmath>
#include <cstring>
#include <iostream>
namespace MyBase {
    namespace Crypto {
        AES_128::AES_128(const char* key) {
            memcpy(__key, key, 4*sizeof(int));
            __key_expand();
            std::string arr;
            arr.resize(44*4+1);
            memcpy(arr.data(), __key, 44*4+1);
            arr.back() = 0;
        }
        AES_128::~AES_128() {}

        unsigned char AES_128::__mul(unsigned char a, unsigned char b) {
            if (!a || !b) return 0;
            if (a==1) return b;
            if (b==1) return a;

            unsigned int out = 0;
            while (b) {
                int index = std::floor(std::log2(b));
                out^=a<<index;
                b -= 1<<index;
            }
            if (out>=256) out ^= 0x0000011B;
            return out;
        }

        void AES_128::encrypt(char* plaintext, char* cipher) {
            memcpy(cipher, plaintext, 16);
            __addRoundKey(cipher, 0);
            for (int i = 1; i<=10 ;i++) {
                for (int i = 0; i<16; i++) cipher[i] = SBox::get(cipher[i]);
                //Sub text
                {
                    char sub[16];
                    for (int i = 0; i<16; i++) {
                        int row = i%4, col = i/4;
                        sub[i] = cipher[((col+row)%4)*4 + row];
                    }
                    memcpy(cipher, sub, 16);
                }
                //Mix column
                if (i<10) {
                    for (int col = 0; col<4; col++) {
                        char code[4];
                        code[0] = __mul(cipher[col*4], 0x02) ^ __mul(cipher[col*4+1], 0x03) ^ cipher[col*4+2] ^ cipher[col*4+3];
                        code[1] = cipher[col*4] ^ __mul(cipher[col*4+1], 0x02) ^ __mul(cipher[col*4+2], 0x03) ^ cipher[col*4+3];
                        code[2] = cipher[col*4] ^ cipher[col*4+1] ^ __mul(cipher[col*4+2], 0x02) ^ __mul(cipher[col*4+3], 0x03);
                        code[3] = __mul(cipher[col*4], 0x03) ^ cipher[col*4+1] ^ cipher[col*4+2] ^ __mul(cipher[col*4+3], 0x02);
                        memcpy(cipher+col*4, code, 4);
                    }
                }
                //
                __addRoundKey(cipher, i);
            }
        }

        void AES_128::__addRoundKey(char* text, const int& index) {
            unsigned char* key = (unsigned char*)(__key+index*4);
            for (int i = 0; i<16; i++) text[i] ^= key[i];
        }

        void AES_128::__key_expand() {
            for (int i = 4, rc = 1; i<44; i++) {
                unsigned int tmp = __key[i-1];
                if (i%4 == 0) {
                    tmp = (tmp >> 8) | (tmp << 24);
                    tmp = SBox::get(tmp);

                    tmp ^= rc;
                    rc <<= 1;

                    if (rc & 0x00000100) rc ^= 0x0000011B;
                }
                __key[i] = __key[i-4] ^ tmp;
            }
        }
    }
}