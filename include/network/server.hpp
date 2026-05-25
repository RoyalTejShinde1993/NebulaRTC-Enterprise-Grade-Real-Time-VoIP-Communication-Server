
#pragma once
#include <boost/asio.hpp>

class VoIPServer {
public:
    VoIPServer(boost::asio::io_context& io, unsigned short port);
    void start();

private:
    void accept();

    boost::asio::ip::tcp::acceptor acceptor_;
};
