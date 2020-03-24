#include <azmq/socket.hpp>
#include <boost/asio.hpp>
#include <array>
#include <glog/logging.h>

namespace asio = boost::asio;

int main() {
    asio::io_service ios;
    azmq::pull_socket pullSocket(ios);
    pullSocket.connect("tcp://localhost:5557");
    std::array<char, 2560 * 1000> buf;
    for (;;) {
        auto size = pullSocket.receive(asio::buffer(buf));
        LOG(INFO) << std::string(buf.data(), size);
        sleep(1);
    }
}