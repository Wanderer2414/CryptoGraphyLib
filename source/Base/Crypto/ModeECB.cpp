#include "../../../include/Base/Crypto/ModeECB.h"
#include <cassert>
#include <cmath>
#include <cstring>
namespace MyBase {
    namespace Crypto {
        int ECB_128::size() const {
            return __text.size()/16;
        }
        void ECB_128::set_string(const std::string& text) {
            __text = text;
            int offset = std::ceil(1.f*__text.size()/16)*16 - __text.size();
            if (offset) __text.resize(__text.size()+offset, 0);
        }
        std::string ECB_128::get(const int& index) {
            assert(index<__text.size()/16);
            return __text.substr(index*16, 16);
        }
        void ECB_128::push_encrypt(const std::string& cipher, const int& index) {
            assert(index<__text.size()/16 && index>=0);
            memcpy(__text.data()+index*16, cipher.data(), 16);
        }
        void ECB_128::push_decrypt(const std::string& text, const int& index) {
            assert(index<__text.size()/16 && index>=0);
            memcpy(__text.data()+index*16, text.data(), 16);
        }
        Mode* ECB_128::clone() const {
            Mode* mode = new ECB_128(*this);
            return mode;
        }
        std::string ECB_128::get_string() {
            return __text;
        }
    }
}