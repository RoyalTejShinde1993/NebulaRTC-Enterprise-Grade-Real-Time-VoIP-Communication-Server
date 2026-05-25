
#include "sip/sip_parser.hpp"
#include <sstream>

SIPMessage SIPParser::parse(const std::string& raw) {
    SIPMessage msg;

    std::istringstream stream(raw);
    std::string line;

    std::getline(stream, line);

    std::istringstream request(line);
    request >> msg.method >> msg.uri >> msg.version;

    while(std::getline(stream, line)) {
        if(line == "\r") {
            break;
        }

        auto pos = line.find(':');

        if(pos != std::string::npos) {
            auto key = line.substr(0, pos);
            auto value = line.substr(pos + 1);
            msg.headers[key] = value;
        }
    }

    return msg;
}
