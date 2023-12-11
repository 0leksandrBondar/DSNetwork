#pragma once

#include "AbstractSocket.h"

#include <vector>

class Server : public AbstractSocket
{
public:
    void sendMessage(const char* message) override;
    std::string receivingMessage() override;

private:
    std::vector<SOCKET> _clients{};
};
