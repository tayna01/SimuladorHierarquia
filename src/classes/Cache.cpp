#include "Cache.h"
#include <iostream>
#include <cmath>

Cache::Cache(const std::string& nome, int latencia, int associatividade, int num_conjuntos, int tamanho_linha)
    : NivelMemoria(nome, latencia), 
      associatividade(associatividade), 
      num_conjuntos(num_conjuntos), 
      tamanho_linha(tamanho_linha),
      hits(0), 
      misses(0) 
{
    this->bits_offset = log2(tamanho_linha);
    this->bits_indice = log2(num_conjuntos);

    this->conjuntos.resize(num_conjuntos, std::vector<LinhaCache>(associatividade));
}

void Cache::_extrair_partes_endereco(unsigned int endereco, unsigned int& tag, unsigned int& indice) const {

    unsigned int temp = endereco >> this->bits_offset;
    unsigned int mascara_indice = (1 << this->bits_indice) - 1;
    indice = temp & mascara_indice;
    
    tag = temp >> this->bits_indice;
}

int Cache::_encontrar_vitima(unsigned int indice_conjunto) {
    return 0;
}

int Cache::acessar(unsigned int endereco, TipoAcesso tipo, int tempo_global) {
    unsigned int tag, indice;
    _extrair_partes_endereco(endereco, tag, indice);

    std::cout << "-> [" << this->nome << "] Procurando endereco " << endereco << " (Tag: " << tag << ", Indice: " << indice << ")" << std::endl;

    for (auto& linha : this->conjuntos[indice]) {
        if (linha.valido && linha.tag == tag) {
            std::cout << "   HIT na cache " << this->nome << "!" << std::endl;
            this->hits++;
            linha.ultimo_acesso = tempo_global;
            return this->latencia;
        }
    }

    std::cout << "   MISS na cache " << this->nome << "!" << std::endl;
    this->misses++;
    
    int latencia_total = this->latencia;

    latencia_total += this->proximo_nivel->acessar(endereco, TipoAcesso::LEITURA, tempo_global);

    int indice_vitima = _encontrar_vitima(indice);
    LinhaCache& vitima = this->conjuntos[indice][indice_vitima];
    
    vitima.valido = true;
    vitima.tag = tag;
    vitima.ultimo_acesso = tempo_global;

    return latencia_total;
}

void Cache::imprimir_estatisticas() const {
    std::cout << "--- Estatisticas para " << this->nome << " ---" << std::endl;
    int total = hits + misses;
    double taxa_miss = (total > 0) ? (double)misses / total * 100.0 : 0.0;
    std::cout << "  Hits: " << this->hits << std::endl;
    std::cout << "  Misses: " << this->misses << std::endl;
    std::cout << "  Taxa de Miss: " << taxa_miss << "%" << std::endl;
}