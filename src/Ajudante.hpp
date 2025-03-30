#pragma once

#include <string>
//randomização
#include <random>
#include <chrono>

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "../ASCII_Engine/SpriteAnimado.hpp"
#include "../ASCII_Engine/Core/SpriteBase.hpp"
#include "../ASCII_Engine/TextContainer.hpp"

class Ajudante: public ObjetoDeJogo{
public:
    Ajudante(std::string name, const SpriteAnimado &s, int posL, int posC) : 
    ObjetoDeJogo(name, s, posL, posC), falasTC(TextContainer()) {}

    virtual void carregarFalas(std::string);

    const std::string &falaSorteada();

private:
    TextContainer falasTC;
};