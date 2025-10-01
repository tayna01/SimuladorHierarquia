#include <iostream>
#include "Cache.h"
#include "MemoriaPrincipal.h"

int main() {
    Cache* l1 = new Cache("L1", 1, 4, 16, 64);
    MemoriaPrincipal* ram = new MemoriaPrincipal("RAM", 100);

    l1->ligar_proximo_nivel(ram);

    NivelMemoria* hierarquia = l1;

    int latencia_total = 0;
    int tempo = 0;

    std::cout << "\n--- PRIMEIRO ACESSO (MISS COMPULSORIO) ---" << std::endl;
    // Endereço 1000
    latencia_total += hierarquia->acessar(1000, TipoAcesso::LEITURA, tempo++);
    
    std::cout << "\n--- SEGUNDO ACESSO (DEVE SER HIT) ---" << std::endl;
    // Acessando o mesmo endereço 1000 novamente
    latencia_total += hierarquia->acessar(1000, TipoAcesso::LEITURA, tempo++);

    std::cout << "\n--- TERCEIRO ACESSO (OUTRO MISS) ---" << std::endl;
    // Endereço 20000, que deve mapear para um local diferente
    latencia_total += hierarquia->acessar(20000, TipoAcesso::LEITURA, tempo++);
    
    std::cout << "\n==========================================" << std::endl;
    std::cout << "Latencia Total Acumulada: " << latencia_total << " ciclos" << std::endl;
    std::cout << "==========================================\n" << std::endl;


    // --- 3. Imprimir Estatísticas ---
    l1->imprimir_estatisticas();
    std::cout << std::endl;
    ram->imprimir_estatisticas();

    // --- 4. Limpar Memória ---
    delete l1;
    delete ram;

    return 0;
}