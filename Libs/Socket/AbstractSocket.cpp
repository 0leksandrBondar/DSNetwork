#include "AbstractSocket.h"

void AbstractSocket::setupSocketAddress(AbstractSocket::AddressFamily addressFamily,
                                        const std::string& address, USHORT port)
{
    _address.sin_port = htons(port);
    _address.sin_family = AF_INET;
    _address.sin_addr.s_addr = inet_addr("127.0.0.1");
}

void AbstractSocket::closeSocket() const { closesocket(_socketDescriptor); }

bool AbstractSocket::isValid() const { return _socketDescriptor != INVALID_SOCKET; }
