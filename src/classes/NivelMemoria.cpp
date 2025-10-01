#include "NivelMemoria.h"

NivelMemoria::NivelMemoria(const std::string &n, int l)
    : nome(n), latencia(l), proximo_nivel(nullptr)
{
}

void NivelMemoria::ligar_proximo_nivel(NivelMemoria *proximo)
{
    this->proximo_nivel = proximo;
}

std::string NivelMemoria::get_nome() const
{
    return this->nome;
}