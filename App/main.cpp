#include "TCPSocket.h"

#include <iostream>

int main()
{
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0)
    {
        std::cout << "WSAStartup failed: " << iResult << "\n";
        return 1;
    }

    TCPSocket socket;
    if (socket.isValid())
    {
        socket.setupSocketAddress(AbstractSocket::AddressFamily::IPv4, "127.0.0.1", 2023);
        socket.connectToSockAddr();
    }
    else
    {
        std::cout << "socket can not connect to address";
    }

    socket.closeSocket();
    WSACleanup();
    return 0;
}