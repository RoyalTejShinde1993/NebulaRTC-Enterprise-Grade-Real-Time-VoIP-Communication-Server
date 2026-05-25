
#pragma once
#include <vector>
#include <cstdint>

class MediaSession {
public:
    void start();
    void stop();
    void send_rtp_packet(const std::vector<uint8_t>& payload);
};
