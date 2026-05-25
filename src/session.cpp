
#include "network/session.hpp"
#include "core/logger.hpp"

using boost::asio::ip::tcp;

Session::Session(tcp::socket socket)
    : socket_(std::move(socket)) {}

void Session::start() {
    Logger::info("Session Started");
    read();
}

void Session::read() {
    auto self(shared_from_this());

    socket_.async_read_some(
        boost::asio::buffer(buffer_),
        [this, self](boost::system::error_code ec, std::size_t length) {
            if(!ec) {
                std::string request(buffer_.data(), length);
                process(request);
                read();
            } else {
                Logger::error("Client Disconnected");
            }
        });
}

void Session::process(const std::string& request) {
    Logger::info("Received Request: " + request);

    if(request.find("INVITE") != std::string::npos) {
        write("SIP/2.0 200 OK\r\n");
    } else if(request.find("BYE") != std::string::npos) {
        write("SIP/2.0 200 BYE\r\n");
    } else if(request.find("OPTIONS") != std::string::npos) {
        write("SIP/2.0 200 OPTIONS\r\n");
    } else {
        write("SIP/2.0 400 BAD REQUEST\r\n");
    }
}

void Session::write(const std::string& response) {
    auto self(shared_from_this());

    boost::asio::async_write(
        socket_,
        boost::asio::buffer(response),
        [this, self](boost::system::error_code ec, std::size_t) {
            if(ec) {
                Logger::error("Write Failed");
            }
        });
}
