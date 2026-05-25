
#pragma once

#include "sip/sip_message.hpp"

class SIPParser {
public:
    SIPMessage parse(const std::string& raw);
};
