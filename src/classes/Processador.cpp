#include "Processador.h"
#include <iostream>

Processador::Processador(const std::string &nome, NivelMemoria *cache_l1)
    : nome(nome),
      cache_l1(cache_l1),
      tempo_global(0),
      num_acessos(0),
      ciclos_totais(0)
{
    std::cout << "Processador \"" << nome << "\" inicializado." << std::endl;
}

void Processador::acessar_memoria(unsigned int endereco, TipoAcesso tipo)
{
    // numero de ciclos
    int latencia = cache_l1->acessar(endereco, tipo, tempo_global);

    tempo_global += latencia;
    ciclos_totais += latencia;
    num_acessos++;
}

/**
 * realiza varios acessos a memoria em sequencia pelo metodo acessar_memria
 * 
 * recebe um vetor de endereços da memória e chama o método acessar_memoria para cada um deles
 */
void Processador::executar_acessos_sequencial(const std::vector<unsigned int> &enderecos, TipoAcesso tipo)
{
    for (unsigned int endereco : enderecos)
    {
        acessar_memoria(endereco, tipo);
    }
}

