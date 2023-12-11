#include "AbstractSocket.h"

#include <iostream>

void AbstractSocket::setupSocketAddress(AbstractSocket::AddressFamily addressFamily,
                                        const std::string& address, USHORT port)
{
    _address.sin_port = htons(port);
    _address.sin_family = AF_INET;
    _address.sin_addr.s_addr = inet_addr("127.0.0.1");
}

void AbstractSocket::closeSocket() const { closesocket(_socketDescriptor); }

bool AbstractSocket::isValid() const { return _socketDescriptor != INVALID_SOCKET; }
std::string AbstractSocket::receivingMessage()
{
    unsigned long long messageSize = 0;
    if (::recv(_socketDescriptor, reinterpret_cast<char*>(&messageSize), sizeof(messageSize), 0)
        < 0)
    {
        throw std::runtime_error("Failed to get message size");
    }

    std::string message;
    message.resize(messageSize);
    if (::recv(_socketDescriptor, const_cast<char*>(message.data()), static_cast<int>(messageSize), 0) < 0)
    {
        throw std::runtime_error("Failed to get message size");
    }

    return message;
}

void AbstractSocket::sendMessage(const char* message)
{
    unsigned long long messageSize = std::strlen(message);
    if (::send(_socketDescriptor, reinterpret_cast<const char*>(&messageSize), sizeof(messageSize),
               0)
        < 0)
    {
        throw std::runtime_error("Failed to send message size");
    }

    if (::send(_socketDescriptor, message, static_cast<int>(messageSize), 0) < 0)
    {
        throw std::runtime_error("Failed to send message");
    }
}

// must be overridden in child classes
void AbstractSocket::connectToSockAddr() {}
