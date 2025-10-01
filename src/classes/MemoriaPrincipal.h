#ifndef MEMORIAPRINCIPAL_H
#define MEMORIAPRINCIPAL_H

#include "NivelMemoria.h"

class MemoriaPrincipal : public NivelMemoria {
public:
    MemoriaPrincipal(const std::string& nome, int latencia);

    int acessar(unsigned int endereco, TipoAcesso tipo, int tempo_global) override;

    void imprimir_estatisticas() const;

private:
    int leituras;
    int escritas;
};

#endif