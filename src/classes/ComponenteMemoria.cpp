#include <iostream>
#include <vector>
#include <memory>
#include <random>

class ComponenteMemoria {
protected:
    std::string nome;
    int latencia;
    ComponenteMemoria* proximoNivel;

public:
    ComponenteMemoria(std::string n, int l) : nome(n), latencia(l), proximoNivel(nullptr) {}
    virtual ~ComponenteMemoria() = default;

    void setProximoNivel(ComponenteMemoria* prox) { proximoNivel = prox; }

    virtual int acessar(uint32_t endereco, TipoAcesso tipo) = 0;
};