#include <azmq/socket.hpp>
#include <boost/asio.hpp>
#include <array>
#include <glog/logging.h>
#include <boost/make_shared.hpp>
#include <boost/bind.hpp>
#include <azmq/actor.hpp>

namespace asio = boost::asio;

/**
 * rep req模式的服务端
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv) {
    asio::io_service ios;
    azmq::rep_socket reponseSocket(ios);
    reponseSocket.bind("tcp://127.0.0.1:9999");
    std::array<char, 2560 * 1000> buf;
    for (;;) {
        auto size = reponseSocket.receive(asio::buffer(buf));
        LOG(INFO) << size << std::string(buf.data(), size);
        sleep(10);
        LOG(INFO) << "sta;rt send ";
        reponseSocket.send(asio::buffer(buf, size));
    }
}
