
#pragma once
#include <string>
#include <unordered_map>

struct SIPMessage {
    std::string method;
    std::string uri;
    std::string version;
    std::unordered_map<std::string, std::string> headers;
    std::string body;
};
