#ifndef UTILS_H_
#define UTILS_H_

#include <string>
struct Utils {
    static std::string to_lower(const std::string &str) {
        char ret[str.length() -1];
        for (size_t i = 0; i < str.length(); i++) {
            ret[i] = std::tolower(str[i]);
        }
        return std::string(ret);
    }
};

#endif  // UTILS_H_
