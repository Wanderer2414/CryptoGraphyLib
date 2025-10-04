#ifndef CRYPTO_AES_ENCRYPTION_H
#define CRYPTO_AES_ENCRYPTION_H
namespace MyBase {
    namespace Crypto {
        class AES_128 {
        public:
            AES_128(const char* key);
            ~AES_128();
            void encrypt(char* plainttext, char* cipher);

            AES_128(const AES_128&) = delete;
            AES_128(AES_128&&) = delete;
            AES_128& operator=(const AES_128) = delete;
        private:
            unsigned int __key[44];
            unsigned char __mul(unsigned char a, unsigned char b);
            void __key_expand();
            void __addRoundKey(char* text, const int& index);
        };
    }
}
#endif