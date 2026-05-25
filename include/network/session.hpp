
#pragma once

#include <boost/asio.hpp>
#include <array>
#include <memory>

class Session : public std::enable_shared_from_this<Session> {
public:
    explicit Session(boost::asio::ip::tcp::socket socket);

    void start();

private:
    void read();
    void process(const std::string& request);
    void write(const std::string& response);

    boost::asio::ip::tcp::socket socket_;
    std::array<char, 4096> buffer_;
};
