#include "../../../include/Base/PKCS#7/Pad.h"
#include <string>

namespace MyBase {
    namespace PKCS_7 {
        std::string pad(const std::string& text, char padding, const int& destination_size) {
            std::string out(text);
            out.resize(destination_size, padding);
            return out;
        }
    }
}