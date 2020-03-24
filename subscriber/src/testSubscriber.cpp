#include <azmq/socket.hpp>
#include <boost/asio.hpp>
#include <array>
#include <glog/logging.h>

namespace asio = boost::asio;

int main() {
    asio::io_service ios;
    azmq::sub_socket subSocket(ios);
    subSocket.connect("tcp://127.0.0.1:10000");
    subSocket.set_option(azmq::socket::subscribe("TESTMESSAGE"));
    std::array<char, 2560 * 1000> buf;
    for (;;) {
        auto size = subSocket.receive(asio::buffer(buf));
        LOG(INFO) << std::string(buf.data(), size);
        sleep(1);
    }
}