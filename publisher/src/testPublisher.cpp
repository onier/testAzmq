#include <azmq/socket.hpp>
#include <boost/asio.hpp>
#include <array>
#include <glog/logging.h>

namespace asio = boost::asio;

int main() {
    asio::io_service ios;
    azmq::pub_socket pubSocket(ios);
    pubSocket.bind("tcp://127.0.0.1:10000");
    for (int n = 0;; n++) {
        std::string text = "TESTMESSAGE" + std::to_string(n%10);
        LOG(INFO)<<text;
        pubSocket.send(asio::buffer(text));
        sleep(1);
    }
}
