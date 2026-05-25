
#include "network/server.hpp"
#include "network/session.hpp"
#include "core/logger.hpp"

using boost::asio::ip::tcp;

VoIPServer::VoIPServer(boost::asio::io_context& io, unsigned short port)
    : acceptor_(io, tcp::endpoint(tcp::v4(), port)) {}

void VoIPServer::start() {
    Logger::info("NebulaRTC Server Started");
    accept();
}

void VoIPServer::accept() {
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket) {
            if(!ec) {
                Logger::info("Client Connected");
                std::make_shared<Session>(std::move(socket))->start();
            }

            accept();
        }
    );
}
