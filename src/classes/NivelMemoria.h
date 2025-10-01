#ifndef NIVELMEMORIA_H
#define NIVELMEMORIA_H

#include <string>

enum class TipoAcesso
{
    LEITURA,
    ESCRITA
};

class NivelMemoria
{
public:
    NivelMemoria(const std::string &nome, int latencia);

    virtual ~NivelMemoria() = default;

    virtual int acessar(unsigned int endereco, TipoAcesso tipo, int tempo_global) = 0;

    void ligar_proximo_nivel(NivelMemoria *proximo);

    std::string get_nome() const;

protected:
    std::string nome;
    int latencia;
    NivelMemoria *proximo_nivel;
};

#endif