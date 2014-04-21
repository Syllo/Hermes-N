#ifndef __SERVEUR_H
#define __SERVEUR_H

#include <vector>
#include <string>
#include <stack>

typedef struct{
    std::string name;
    std::string ipaddr;
} client;

typedef struct{
    std::string name;
    std::vector< clients* > clients;
} alias;

class Serveur{
    public:
        int sendMesg(std::string name);
        std::stack<std::string>& recvMesg(void);
    private:
        std::vector<client> clients;
        std::vector<alias> aliases;
}

#endif //__SERVEUR_H
