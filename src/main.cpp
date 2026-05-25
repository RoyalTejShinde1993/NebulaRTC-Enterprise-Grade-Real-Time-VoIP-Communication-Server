
#include "network/server.hpp"
#include "core/logger.hpp"

#include <boost/asio.hpp>
#include <thread>
#include <vector>
#include <openssl/ssl.h>

int main() {
    SSL_library_init();

    boost::asio::io_context io;

    VoIPServer server(io, 5060);
    server.start();

    constexpr int workers = 4;

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
