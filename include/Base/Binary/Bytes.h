#ifndef MYBASE_BINARY_H
#define MYBASE_BINARY_H
#include <ostream>
namespace MyBase {
    namespace Binary {
        class Hex;
        class Base64;
        class Bytes {
        public:
            Bytes(char c);
            Bytes(const unsigned int& val);
            Bytes(const std::string& text);
            ~Bytes();

            char most() const;
            int size() const;
            int count() const;
            Bytes(const Bytes& byte);
            Bytes(Bytes&& byte) noexcept;

            Bytes sub(const int& start, const int n) const;
            Bytes get_seperate(const int& start, const int& distance) const;

            Bytes& operator=(const Bytes&);
            Bytes operator~() const;
            Bytes operator|(const Bytes& bin) const;
            Bytes& operator|=(const Bytes& bin);

            Bytes operator+(const Bytes& bin) const;
            Bytes& operator+=(const Bytes& bin);

            Bytes operator&(const Bytes& bin) const;
            Bytes& operator&=(const Bytes& bin);

            Bytes operator|(char c) const;
            Bytes& operator|=(char c);
            Bytes operator&(char c) const;
            Bytes& operator&=(char c);

            Bytes operator|(const std::string& str) const;
            Bytes& operator|=(const std::string& str);
            Bytes operator&(const std::string& str) const;
            Bytes& operator&=(const std::string& str);

            unsigned char& operator[](const int& index);
            const unsigned char& operator[](const int& index) const;
            operator std::string() const;
            friend std::ostream& operator<<(std::ostream& out, const Bytes& bin);
            friend char* operator<<(char*, const Bytes& bin);
            friend class Hex;
            friend class Base64;
        private:
            Bytes();
            unsigned char* __buffer;
            int __size;
        };
    }
}
#endif