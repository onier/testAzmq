#include <azmq/socket.hpp>
#include <boost/asio.hpp>
#include <array>
#include <glog/logging.h>
#include <boost/make_shared.hpp>
#include <boost/bind.hpp>
#include <azmq/actor.hpp>

namespace asio = boost::asio;

int main() {
    asio::io_service ios;
    azmq::push_socket pushSocket(ios);
    pushSocket.bind("tcp://*:5557");
    for (int n = 0;; n++) {
        std::string text = "pushSocket" + std::to_string(n%10);
        LOG(INFO)<<text;
        pushSocket.send(asio::buffer(text));
        sleep(1);
    }
}