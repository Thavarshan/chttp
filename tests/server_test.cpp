#include "../vendor/gtest/include/gtest/gtest.h"
#include "../vendor/boost/asio.hpp"
#include <memory>
#include "../src/include/server.h"

class ServerTest : public ::testing::Test {
protected:
    boost::asio::io_service io_service;
    std::unique_ptr<Server> server;

    void SetUp() override {
        server = std::make_unique<Server>(io_service, 8080);
        std::thread serverThread([&]() {
            io_service.run();
        });
        serverThread.detach();
    }

    void TearDown() override {
        io_service.stop();
    }
};

TEST_F(ServerTest, TestServerResponse) {
    boost::asio::io_service clientService;
    boost::asio::ip::tcp::socket clientSocket(clientService);
    boost::asio::ip::tcp::resolver resolver(clientService);
    boost::asio::connect(clientSocket, resolver.resolve("localhost", "8080"));

    std::string request = "GET / HTTP/1.1\r\n\r\n";
    boost::asio::write(clientSocket, boost::asio::buffer(request));

    boost::asio::streambuf responseBuffer;
    boost::asio::read_until(clientSocket, responseBuffer, "\r\n\r\n");
    std::string response((std::istreambuf_iterator<char>(&responseBuffer)), std::istreambuf_iterator<char>());

    EXPECT_EQ(response, "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
