#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "VSocket.h"

class Cliente {
private:
    const char * os;
    const char * osi;
    const char * ose;
    VSocket * socket;
    
    std::vector<std::string> fetchedFigures;
    void LIST_FIGURES();

    std::string selectFigure();
    std::string selectPart();
    std::string GET_FIGURE();
    void FIGURE_PARTS(const std::string& html);
    void trim(std::string &s);

public:
    Cliente();
    ~Cliente();
    void ejecutar();
};

#endif // CLIENTE_H
