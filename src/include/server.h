#ifndef SERVER_H
#define SERVER_H

#include "../../vendor/boost/asio.hpp"
#include <memory>
#include <thread>

class Server {
public:
    Server(boost::asio::io_service& io_service, int port);

private:
    void startAccept();
    void handleRequest(std::shared_ptr<boost::asio::ip::tcp::socket> socket);

    boost::asio::ip::tcp::acceptor acceptor_;
};

#endif // SERVER_H
