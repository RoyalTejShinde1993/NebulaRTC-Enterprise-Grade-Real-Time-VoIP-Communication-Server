
#include "network/server.hpp"
#include "core/logger.hpp"

#include <boost/asio.hpp>
#include <openssl/ssl.h>
#include <thread>
#include <vector>

int main() {
    SSL_library_init();

    constexpr unsigned short port = 5060;
    constexpr int workers = 4;

    boost::asio::io_context io;

    VoIPServer server(io, port);
    server.start();

    Logger::info("Server initialized successfully");

    std::vector<std::thread> pool;

    for(int i = 0; i < workers; ++i) {
        pool.emplace_back([&io]() {
            io.run();
        });
    }

    for(auto& t : pool) {
        t.join();
    }

    return 0;
}
