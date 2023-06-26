#include "include/server.h"

int main()
{
    try {
        boost::asio::io_service io_service;
        HTTPServer server(io_service, 8080);
        io_service.run();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
