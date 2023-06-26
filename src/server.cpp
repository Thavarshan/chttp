#include "../vendor/boost/asio.hpp"

class Server {
public:
    Server(boost::asio::io_service& io_service, int port)
        : acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
    {
        startAccept();
    }

private:
    void startAccept()
    {
        auto newConnection = std::make_shared<boost::asio::ip::tcp::socket>(acceptor_.get_io_service());
        acceptor_.async_accept(*newConnection,
            [this, newConnection](const boost::system::error_code& error) {
                if (!error) {
                    // Handle the incoming connection
                    handleRequest(newConnection);
                }
                startAccept();
            });
    }

    void handleRequest(std::shared_ptr<boost::asio::ip::tcp::socket> socket)
    {
        boost::asio::streambuf buffer;
        boost::asio::read_until(*socket, buffer, "\r\n");

        // Simulate request processing
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Prepare response
        std::string response = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!";
        boost::asio::write(*socket, boost::asio::buffer(response));

        socket->shutdown(boost::asio::ip::tcp::socket::shutdown_both);
    }

    boost::asio::ip::tcp::acceptor acceptor_;
};
