#ifndef PKCS_7_PADDING_H
#define PKCS_7_PADDING_H
#include <string>
namespace MyBase {
    namespace PKCS_7 {
        std::string pad(const std::string& text, char padding, const int& destination_size);
    }
}
#endif