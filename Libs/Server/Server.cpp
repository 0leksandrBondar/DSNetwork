#include "Server.h"
void Server::sendMessage(const char* message) { AbstractSocket::sendMessage(message); }
std::string Server::receivingMessage()
{
    unsigned long long messageSize = 0;
    if (::recv(_socketDescriptor, reinterpret_cast<char*>(&messageSize), sizeof(messageSize), 0)
        < 0)
    {
        throw std::runtime_error("Failed to get message size");
    }

    std::string message;
    message.resize(messageSize);
    if (::recv(_socketDescriptor, const_cast<char*>(message.data()), static_cast<int>(messageSize),
               0)
        < 0)
    {
        throw std::runtime_error("Failed to get message size");
    }

    return message;
}
