#ifndef __MESSAGESERVICE_H
#define __MESSAGESERVICE_H

#include "messageservice.hh"

class MessageService_ChatIMPL : public POA_MessageService::Chat{
    public:
        MessageService_ChatIMPL();
        virtual ~MessageService_ChatIMPL();

        char* status();
        void inMessage(const char* message);
        void changeStatus(const MessageService::Client& cli, const char* status);
    private:
};

class MessageService_ConnectionsIMPL : public POA_MessageService::Connections{
    public:
        MessageService_ConnectionsIMPL();
        virtual ~MessageService_ConnectionsIMPL();
        void connect(const MessageService::Client& cli);
        void disconnect(const MessageService::Client& cli);
    private:
};

#endif // ( __MESSAGESERVICE_H )
