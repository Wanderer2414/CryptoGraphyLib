#ifndef MODE_EBC_H
#define MODE_EBC_H
#include "Mode.h"
#include <string>
namespace MyBase {
    namespace Crypto {
        class ECB_128: public Mode {
        public:
        private:
            int size() const override;
            void set_string(const std::string& text) override;
            std::string get(const int& index) override;
            void push_encrypt(const std::string&, const int& index) override;
            void push_decrypt(const std::string&, const int& index) override;
            std::string get_string() override;
            Mode* clone() const override;

            std::string __text;
        };
    }
}
#endif