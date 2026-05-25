
#include "media/media_session.hpp"
#include <iostream>

void MediaSession::start() {
    std::cout << "Media session started" << std::endl;
}

void MediaSession::stop() {
    std::cout << "Media session stopped" << std::endl;
}

void MediaSession::send_rtp_packet(const std::vector<uint8_t>& payload) {
    std::cout << "Sending RTP packet of size: " << payload.size() << std::endl;
}
