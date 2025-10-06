#include "../../../include/Base/Crypto/ModeCBC.h"
#include <cassert>
#include <cmath>
#include <cstring>
namespace MyBase {
    namespace Crypto {
        CBC_128::CBC_128() {
            __iv.resize(16, 0);
        }
        int CBC_128::size() const {
            return __text.size()/16;
        }
        void CBC_128::setIV(const std::string& iv) {
            __iv = iv;
            __iv.resize(16, 0);
        }
        void CBC_128::set_string(const std::string& text) {
            __text = text;
            int offset = std::ceil(1.f*__text.size()/16)*16 - __text.size();
            if (offset) __text.resize(__text.size()+offset, 0);
            for (int i = 0; i<16; i++) __text[i] ^= __iv[i];
        }
        std::string CBC_128::get(const int& index) {
            assert(index<__text.size()/16);
            return __text.substr(index*16, 16);
        }
        void CBC_128::push_encrypt(const std::string& cipher, const int& index) {
            assert(index<__text.size()/16 && index>=0);
            memcpy(__text.data()+index*16, cipher.data(), 16);
            if (index<__text.size()/16-1) {
                int offset = index*16 + 16;
                for (int i = 0; i<16; i++) __text[i+offset] ^= cipher[i];
            }
        }
        void CBC_128::push_decrypt(const std::string& text, const int& index) {
            assert(index<__text.size()/16 && index>=0);
            int offset = index*16;
            
            if (index>0)
                for (int i = 0; i<16; i++) 
                    __text[i+offset] = text[i] ^ __text[i+offset-16];
            else memcpy(__text.data(), text.data(), 16);
        }
        Mode* CBC_128::clone() const {
            Mode* mode = new CBC_128(*this);
            return mode;
        }
        std::string CBC_128::get_string() {
            for (int i = 0; i<16; i++) __text[i] ^= __iv[i];
            return __text;
        }
    }
}