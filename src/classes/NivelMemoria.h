#ifndef NIVELMEMORIA_H
#define NIVELMEMORIA_H

#include <string>

// Enum para deixar o código mais legível
enum class TipoAcesso {
    LEITURA,
    ESCRITA
};

class NivelMemoria {
public:
    // Construtor
    NivelMemoria(const std::string& nome, int latencia);
    
    // Destrutor virtual (essencial!)
    virtual ~NivelMemoria() = default;

    // A função virtual pura que define o "contrato"
    virtual int acessar(unsigned int endereco, TipoAcesso tipo, int tempo_global) = 0;

    // Método para conectar a hierarquia
    void ligar_proximo_nivel(NivelMemoria* proximo);
    
    // Getter para o nome
    std::string get_nome() const;

protected:
    std::string nome;
    int latencia;
    NivelMemoria* proximo_nivel;
};

#endif // NIVELMEMORIA_H