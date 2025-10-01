#include "MemoriaPrincipal.h"
#include <iostream>

MemoriaPrincipal::MemoriaPrincipal(const std::string& nome, int latencia)
    : NivelMemoria(nome, latencia), leituras(0), escritas(0) {}

int MemoriaPrincipal::acessar(unsigned int endereco, TipoAcesso tipo, int tempo_global) {
    std::cout << "--> [" << this->nome << "] Acessando endereco " << endereco << ". Fim da linha." << std::endl;
    
    if (tipo == TipoAcesso::LEITURA) {
        leituras++;
    } else {
        escritas++;
    }
    
    return this->latencia;
}

void MemoriaPrincipal::imprimir_estatisticas() const {
    std::cout << "--- Estatisticas para " << this->nome << " ---" << std::endl;
    std::cout << "  Leituras: " << this->leituras << std::endl;
    std::cout << "  Escritas: " << this->escritas << std::endl;
}