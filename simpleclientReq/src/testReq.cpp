#include <azmq/socket.hpp>
#include <boost/asio.hpp>
#include <array>
#include <glog/logging.h>

namespace asio = boost::asio;

int main(int argc, char **argv) {
    asio::io_service ios;
    azmq::req_socket reqSocket(ios);
//    reqSocket.set_option(azmq::socket::snd_timeo(200));
//    reqSocket.set_option(azmq::socket::rcv_timeo(200));
    reqSocket.connect("tcp://127.0.0.1:9999");
    reqSocket.send(asio::buffer("hello"));
    std::array<char, 2560 * 1000> buf;
    auto size = reqSocket.receive(asio::buffer(buf));
    LOG(INFO) << size;
}