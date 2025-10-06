#ifndef CRYPTO_AES_ENCRYPTION_H
#define CRYPTO_AES_ENCRYPTION_H
#include "Mode.h"
#include "ModeCBC.h"
#include <string>
namespace MyBase {
    namespace Crypto {
        class AES_128 {
        public:
            AES_128(const char* key, Mode* mode = 0);
            ~AES_128();

            std::string encrypt(const std::string& plaintext);
            std::string decrypt(const std::string& cipher);
            AES_128(const AES_128&) = delete;
            AES_128(AES_128&&) = delete;
            AES_128& operator=(const AES_128) = delete;
        private:
            Mode* __mode;
            unsigned int __key[44];
            unsigned char __mul(unsigned char a, unsigned char b);
            void __key_expand();
            void __addRoundKey(char* text, const int& index);
            void __encrypt(char* plainttext, char* cipher);
            void __decrypt(char* plainttext, char* cipher);
        };
    }
}
#endif