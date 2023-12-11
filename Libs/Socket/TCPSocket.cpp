#include "TCPSocket.h"

#include <iostream>

TCPSocket::TCPSocket(AbstractSocket::AddressFamily addressFamily)
{
    _socketDescriptor = socket(static_cast<int>(addressFamily), static_cast<int>(_socketType),
                               static_cast<int>(_protocol));
}

void TCPSocket::connectToSockAddr()
{
    if (connect(_socketDescriptor, (SOCKADDR*)&_address, sizeof(_address)) == SOCKET_ERROR)
    {
        std::cerr << "Failed to connect: " << WSAGetLastError() << "\n";
        WSACleanup();
        closeSocket();
    }
    else
    {
        std::cout << "Successfully Connected\n";
    }
}
