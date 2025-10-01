#ifndef CACHE_H
#define CACHE_H

#include "NivelMemoria.h"
#include <vector>

struct LinhaCache {
    bool valido = false;
    bool sujo = false;
    unsigned int tag = 0;
    int ultimo_acesso = 0;
};

class Cache : public NivelMemoria {
public:
    Cache(const std::string& nome, int latencia, int associatividade, int num_conjuntos, int tamanho_linha);

    int acessar(unsigned int endereco, TipoAcesso tipo, int tempo_global) override;
    
    void imprimir_estatisticas() const;

private:
    std::vector<std::vector<LinhaCache>> conjuntos;

    int associatividade;
    int num_conjuntos;
    int tamanho_linha;

    int hits;
    int misses;

    int bits_offset;
    int bits_indice;

    void _extrair_partes_endereco(unsigned int endereco, unsigned int& tag, unsigned int& indice) const;
    int _encontrar_vitima(unsigned int indice_conjunto);
};

#endif