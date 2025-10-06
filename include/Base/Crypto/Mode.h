#ifndef CRYPTO_MODE_H
#define CRYPTO_MODE_H
#include <string>
namespace MyBase {
    namespace Crypto {
        class Mode {
        public:
            friend class AES_128;
            virtual ~Mode() = 0;
        private:
            virtual int size() const =0;
            virtual Mode* clone() const =0;
            virtual void set_string(const std::string& text) = 0;
            virtual std::string get(const int& index) = 0;
            virtual void push_encrypt(const std::string&, const int& index) = 0;
            virtual void push_decrypt(const std::string&, const int& index) = 0;
            virtual std::string get_string() = 0;
        };
    }
}
#endif