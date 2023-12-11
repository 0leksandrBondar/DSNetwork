#pragma once

#include <string>
#include <winsock2.h>

class AbstractSocket
{
public:
    enum class AddressFamily
    {
        IPv4 = AF_INET,
        IPv6 = AF_INET6
    };
    enum class SocketType
    {
        UNDEFINED,
        DGRAM = SOCK_DGRAM,
        STREAM = SOCK_STREAM
    };
    enum class Protocol
    {
        AUTO = 0,
        TCP = IPPROTO_TCP,
        UDP = IPPROTO_UDP,
    };

    void setupSocketAddress(AddressFamily addressFamily, const std::string& address, USHORT port);

    void closeSocket() const;
    bool isValid() const;

protected:
    virtual void connectToSockAddr();
    virtual std::string receivingMessage();
    virtual void sendMessage(const char* message);

protected:
    std::string _dataReceived{};
    SOCKET _socketDescriptor{};
    sockaddr_in _address;
};
