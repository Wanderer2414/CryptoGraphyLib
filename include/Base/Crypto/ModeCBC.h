#ifndef MODE_CBC_H
#define MODE_CBC_H
#include "Mode.h"
#include <string>
namespace MyBase {
    namespace Crypto {
        class CBC_128: public Mode {
        public:
            CBC_128();
            void setIV(const std::string& iv);
        private:
            int size() const override;
            void set_string(const std::string& text) override;
            std::string get(const int& index) override;
            void push_encrypt(const std::string&, const int& index) override;
            void push_decrypt(const std::string&, const int& index) override;
            std::string get_string() override;
            Mode* clone() const override;

            std::string __iv;
            std::string __text;
        };
    }
}
#endif