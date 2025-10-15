#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include "NivelMemoria.h"
#include <memory>
#include <string>
#include <vector>

class Processador
{
public:
    Processador(const std::string &nome, NivelMemoria *cache_l1);

    void acessar_memoria(unsigned int endereco, TipoAcesso tipo);

    void executar_acessos_sequencial(const std::vector<unsigned int> &enderecos, TipoAcesso tipo);

    // void executar_acessos_aleatorio(const std::vector<unsigned int> &enderecos, TipoAcesso tipo);

    // int obter_tempo_total() const;

    //int obter_num_acessos() const;

    //void imprimir_estatisticas() const;

    //void resetar();

private:
    std::string nome;
    NivelMemoria *cache_l1;

    int tempo_global;
    int num_acessos;
    int ciclos_totais;
};

#endif