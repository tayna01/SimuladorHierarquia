#ifndef CACHE_H
#define CACHE_H

#include "NivelMemoria.h"
#include <vector>

// Estrutura auxiliar para representar uma linha da cache
struct LinhaCache {
    bool valido = false;
    bool sujo = false; // Para write-back (não usado nesta versão)
    unsigned int tag = 0;
    int ultimo_acesso = 0; // Para LRU
};

class Cache : public NivelMemoria {
public:
    Cache(const std::string& nome, int latencia, int associatividade, int num_conjuntos, int tamanho_linha);

    // Implementação do "contrato"
    int acessar(unsigned int endereco, TipoAcesso tipo, int tempo_global) override;
    
    void imprimir_estatisticas() const;

private:
    // Estrutura de dados principal da cache
    std::vector<std::vector<LinhaCache>> conjuntos;

    // Parâmetros da cache
    int associatividade;
    int num_conjuntos;
    int tamanho_linha;

    // Estatísticas
    int hits;
    int misses;

    // Bits para decodificação de endereço
    int bits_offset;
    int bits_indice;

    // Métodos auxiliares privados
    void _extrair_partes_endereco(unsigned int endereco, unsigned int& tag, unsigned int& indice) const;
    int _encontrar_vitima(unsigned int indice_conjunto);
};

#endif // CACHE_H