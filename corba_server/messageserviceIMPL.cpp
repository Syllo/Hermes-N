#include "messageserviceIMPL.h"

MessageService_ChatIMPL::MessageService_ChatIMPL(){
}

MessageService_ChatIMPL::~MessageService_ChatIMPL(){
}

char* MessageService_ChatIMPL::status(){
}

void MessageService_ChatIMPL::inMessage(const chat* message){
}

void MessageService_ChatIMPL::changeStatus(
        const MessageService::Client& cli,
        const char* status){
}

MessageService_ConnectionsIMPL::MessageService_ConnectionIMPL(){
}

MessageService_ConnectionsIMPL::MessageService_ConnectionIMPL(){
}

void MessageService_ConnectionIMPL::connect(const MessageService::Client& cli){
}

void MessageService_ConnectionIMPL::disconnect(const MessageService::Client& cli){
}
