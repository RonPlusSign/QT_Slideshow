//
// Created by andre on 12/07/21.
//

#include <string>
#include "utils.h"

bool endsWith(const std::string &str, const std::string &ending) {
    return str.size() >= ending.size() && 0 == str.compare(str.size() - ending.size(), ending.size(), ending);
}