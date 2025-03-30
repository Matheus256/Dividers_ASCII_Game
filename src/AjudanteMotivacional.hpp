#pragma once

#include <string>
//randomização
#include <random>
#include <chrono>

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "../ASCII_Engine/SpriteAnimado.hpp"
#include "../ASCII_Engine/Core/SpriteBase.hpp"
#include "../ASCII_Engine/TextContainer.hpp"

class AjudanteMotivacional: public Ajudante{
public:
    AjudanteMotivacional(std::string name, const SpriteAnimado &s, int posL, int posC) : 
    Ajudante(name, s, posL, posC) {}

    void carregarFalas(std::string) override{Ajudante::carregarFalas("rsc/falas_incentivadoras.txt");}

private:
    TextContainer falasTC;
};