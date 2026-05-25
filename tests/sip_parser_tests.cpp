
#include "sip/sip_parser.hpp"
#include <cassert>

int main() {
    SIPParser parser;

    auto msg = parser.parse(
        "INVITE sip:test@example.com SIP/2.0\r\n"
    );

    assert(msg.method == "INVITE");

    return 0;
}
