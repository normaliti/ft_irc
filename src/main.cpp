#include <iostream>
#include <cstdlib>
#include "src/Server/SocketServer.hpp"
#include "ApplicationData.hpp"
int main(int argc, char *argv[]) {

    int port = std::atoi(argv[1]);

    SocketServer ss(port, 10);
    ApplicationData::instance()->server = &ss;
    ApplicationData::instance()->serverName = "ft_irc.42";
    if (argc == 3)
        ApplicationData::instance()->password = std::string(argv[2]);

    ss.Listen();
    ss.Loop();

    return 0;
}
