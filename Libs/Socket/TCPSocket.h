#pragma once

#include "AbstractSocket.h"

#include <string>

class TCPSocket : public AbstractSocket
{
public:
    explicit TCPSocket(AddressFamily addressFamily = AddressFamily::IPv4);

    void connectToSockAddr() override;

private:
    const Protocol _protocol{ Protocol::TCP };
    const SocketType _socketType{ SocketType::STREAM };
};
